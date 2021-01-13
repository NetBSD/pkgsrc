# $NetBSD: show.mk,v 1.28 2021/01/13 18:01:49 gdt Exp $
#
# This file contains some targets that print information gathered from
# variables. They do not modify any variables.
#

# show-tools:
#	Emits a /bin/sh shell script that defines all known tools
#	to the values they have in the pkgsrc infrastructure.
#
show-tools: .PHONY
.for t in ${_USE_TOOLS}
.  if defined(_TOOLS_VARNAME.${t})
	@${ECHO} ${_TOOLS_VARNAME.${t}:Q}=${${_TOOLS_VARNAME.${t}}:Q:Q}
.  endif
.endfor

# show-build-defs:
#	Prints the variables that can be configured by the pkgsrc user
#	in mk.conf, and the effects that those settings have.
#
# Package-settable variables:
#
# BUILD_DEFS
#	The list of variables that influence the build. These variables
#	are user-settable, and their values will be recorded in the
#	binary package.
#
# System-provided variables:
#
# BUILD_DEFS_EFFECTS
#	The list of variables whose values have been set depending on
#	some of the variables in BUILD_DEFS. These variables are system-
#	settable and therefore should not be modified directly by the
#	pkgsrc user or a package maintainer.
#

BUILD_DEFS?=		# none
BUILD_DEFS_EFFECTS?=	# none

.if !empty(PKGSRC_SHOW_BUILD_DEFS:M[yY][eE][sS])
pre-depends-hook: show-build-defs
.endif

show-build-defs: .PHONY
.if !empty(BUILD_DEFS:M*)
	@${ECHO} "=========================================================================="
	@${ECHO} "The following variables will affect the build process of this package,"
	@${ECHO} "${PKGNAME}.  Their current value is shown below:"
	@${ECHO} ""
.  for var in ${BUILD_DEFS:O:u}
.    if !defined(${var})
	@${ECHO} "        * ${var} (not defined)"
.    elif defined(${var}) && empty(${var})
	@${ECHO} "        * ${var} (defined)"
.    else
	@${ECHO} "        * ${var} = "${${var}:Q}
.    endif
.  endfor
.  if !empty(BUILD_DEFS_EFFECTS:M*)
	@${ECHO} ""
	@${ECHO} "Based on these variables, the following variables have been set:"
	@${ECHO} ""
.  endif
.  for var in ${BUILD_DEFS_EFFECTS:O:u}
.    if !defined(${var})
	@${ECHO} "        * ${var} (not defined)"
.    elif defined(${var}) && empty(${var})
	@${ECHO} "        * ${var} (defined, but empty)"
.    else
	@${ECHO} "        * ${var} = "${${var}:Q}
.    endif
.  endfor
	@${ECHO} ""
	@${ECHO} "You may want to abort the process now with CTRL-C and change the value"
	@${ECHO} "of variables in the first group before continuing.  Be sure to run"
	@${ECHO} "\`${MAKE} clean' after the changes."
	@${ECHO} "=========================================================================="
.endif

# show-all:
#	Prints a list of (hopefully) all pkgsrc variables that are visible
#	to the user or the package developer. It is intended to give
#	interested parties a better insight into the inner workings of
#	pkgsrc. Each variable name is prefixed with a "scope":
#
#		* "usr" for user-settable variables,
#		* "pkg" for package-settable variables,
#		* "sys" for system-defined variables.
#
#	The variables are listed in groups (e.g. "build", "extract").
#	For each of these groups, a specialized target show-all-${group}
#	is defined, e.g. "show-all-extract" for the "extract" group.
#
#	CAVEAT: There are a few extreme edge cases in which the variable
#	values that are shown here are not 100% correct. The closest you
#	can get are the following:
#
#		* To see the unexpanded definition of a variable while the
#		  Makefile or an included file is parsed, run "bmake -dcpv",
#		  which adds a lot of debug logging.
#		* To see the unexpanded definition of a variable at the end
#		  of parsing the Makefile, run "bmake -V VARNAME".
#		* To see the expanded value of a variable while the Makefile
#		  or an included file is parsed, add a line of the form
#		  ".info ${VARNAME}" to that makefile.
#		* To see the expanded value of a variable at the end of
#		  parsing the Makefile, run "bmake -v VARNAME".
#
#	In some cases, the actual value of a variable depends on the targets
#	that are given on the command line, or whether bmake is run
#	recursively, or whether a directory inside WRKSRC already exists.
#	There is nothing the pkgsrc infrastructure can do about this.
#
# Keywords: debug show _vargroups
#

# The following types of variables are categorized:
#
# _USER_VARS.*
#	Variables that can be set by the user and whose primary file is
#	this file.
#
# _PKG_VARS.*
#	Variables that can be set by the package and whose primary file
#	is this file.
#
# _SYS_VARS.*
#	Variables that are defined by this file and that are intended to
#	be used by packages.
#
# _DEF_VARS.*
#	All variables that are defined by this file, whether internal or
#	not, primary or not.
#
# _USE_VARS.*
#	All variables that are used by this file, whether internal or
#	not, primary or not.
#
# _IGN_VARS.*
#	All variables that are used or defined by this file, but which
#	are not worth being documented. These are listed to enable pkglint
#	to check whether all variables are covered properly.
#
# Variables that control the presentation of individual variables:
#
# _SORTED_VARS.*
#	A list of patterns describing the variable names to be shown as
#	lists, one word per line, sorted alphabetically.
#
#	Default: # none
#	Example: *_ENV *_FILES SUBST_VARS.*
#
# _LISTED_VARS.*
#	A list of patterns describing the variable names to be shown as
#	lists, one word per line, in the given order.
#
#	Default: # none
#	Example: *_ARGS *_CMD SUBST_SED.*
#
_SHOW_ALL_CATEGORIES=	_USER_VARS _PKG_VARS _SYS_VARS _USE_VARS _DEF_VARS
_LABEL._USER_VARS=	usr
_LABEL._PKG_VARS=	pkg
_LABEL._SYS_VARS=	sys
_LABEL._USE_VARS=	use
_LABEL._DEF_VARS=	def

show-all: .PHONY
.for grp in ${"${.TARGETS:Mshow-all*}":?${_VARGROUPS:O:u}:}
.  for width in ${_VARGROUP_WIDTH.${grp}:U23}

show-all: show-all-${grp}

# In the following code, the variables are evaluated as late as possible.
# This is especially important for variables that use the :sh modifier,
# like SUBST_FILES.pkglocaledir from mk/configure/replace-localedir.mk.
#
# When finally showing the variables, it is unavoidable that variables
# using the :sh modifier may show warnings, for example because ${WRKDIR}
# doesn't exist.

show-all-${grp}: .PHONY
	@${RUN} printf '%s:\n' ${grp:Q}

.    for cat in ${_SHOW_ALL_CATEGORIES}
.      for var in ${${cat}.${grp}}

.        if ${_SORTED_VARS.${grp}:U:@pattern@ ${var:M${pattern}} @:M*}

# multi-valued variables, values are sorted
	${RUN}								\
	if ${!defined(${var}) :? true : false}; then			\
	  printf '  %-6s%-${width}s # undefined\n' ${_LABEL.${cat}} ${var:Q}; \
	elif value=${${var}:U:M*:Q} && test "x$$value" = "x"; then	\
	  printf '  %-6s%-${width}s # empty\n' ${_LABEL.${cat}} ${var:Q}=; \
	else								\
	  printf '  %-6s%-${width}s \\''\n' ${_LABEL.${cat}} ${var:Q}=;	\
	  printf '        %-${width}s %s \\''\n' ${${var}:O:C,\\\$,\$\$\$\$,g:@word@'' ${word:Q}@}; \
	  printf '        %-${width}s # end of %s (sorted)\n' '' ${var:Q}; \
	fi

.        elif ${_LISTED_VARS.${grp}:U:@pattern@ ${var:M${pattern}} @:M*}

# multi-valued variables, preserving original order
	${RUN}								\
	if ${!defined(${var}) :? true : false}; then			\
	  printf '  %-6s%-${width}s # undefined\n' ${_LABEL.${cat}} ${var:Q}; \
	elif value=${${var}:U:M*:Q} && test "x$$value" = "x"; then	\
	  printf '  %-6s%-${width}s # empty\n' ${_LABEL.${cat}} ${var:Q}=; \
	else								\
	  printf '  %-6s%-${width}s \\''\n' ${_LABEL.${cat}} ${var:Q}=;	\
	  printf '        %-${width}s %s \\''\n' ${${var}:C,\\\$,\$\$\$\$,g:@word@'' ${word:Q}@}; \
	  printf '        %-${width}s # end of %s\n' '' ${var:Q};	\
	fi

.        else

# single-valued variables
	${RUN}								\
	if ${!defined(${var}) :? true : false}; then			\
	  printf '  %-6s%-${width}s # undefined\n' ${_LABEL.${cat}} ${var:Q}; \
	elif value=${${var}:U:C,\\\$,\$\$,gW:Q} && test "x$$value" = "x"; then \
	  printf '  %-6s%-${width}s # empty\n' ${_LABEL.${cat}} ${var:Q}=; \
	else								\
	  case "$$value" in (*[\	\ ]) eol="# ends with space";; (*) eol=""; esac; \
	  printf '  %-6s%-${width}s %s\n' ${_LABEL.${cat}} ${var:Q}= "$$value$$eol"; \
	fi

.        endif
.      endfor
.    endfor
	${RUN} printf '\n'
.  endfor
.endfor

.PHONY: show-depends-options
show-depends-options:
	${RUN}                                                          \
	${_DEPENDS_WALK_CMD} ${PKGPATH} |                               \
	while read dir; do                                              \
		${ECHO} "===> Options for $${dir}" &&                   \
		cd ${.CURDIR}/../../$$dir &&                            \
		${RECURSIVE_MAKE} ${MAKEFLAGS} show-options;            \
	done
