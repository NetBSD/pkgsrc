# $NetBSD: show.mk,v 1.15 2018/11/10 10:40:55 rillig Exp $
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
	@${ECHO} "You may want to abort the process now with CTRL-C and change their value"
	@${ECHO} "before continuing.  Be sure to run \`${MAKE} clean' after"
	@${ECHO} "the changes."
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
#	CAVEAT: Some few variable values that are shown here may be
#	misleading. For example, make(1)'s := operator leaves references
#	to undefined variables as-is, so they may be resolved later. So
#	if you want to take a snapshot of the exact value of a variable,
#	you have to use "snapshot!=printf %s ''${var:q}" instead of
#	"snapshot:=${var}".
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
_SHOW_ALL_CATEGORIES=	_USER_VARS _PKG_VARS _SYS_VARS _USE_VARS _DEF_VARS
_LABEL._USER_VARS=	usr
_LABEL._PKG_VARS=	pkg
_LABEL._SYS_VARS=	sys
_LABEL._USE_VARS=	use
_LABEL._DEF_VARS=	def

show-all: .PHONY
.for g in ${_VARGROUPS:O:u}

show-all: show-all-${g}

# In the following code, the variables are evaluated as late as possible.
# This is especially important for variables that use the :sh modifier,
# like SUBST_FILES.pkglocaledir from mk/configure/replace-localedir.mk.
#
# When finally showing the variables, it is unavoidable that variables
# using the :sh modifier may show warnings, for example because ${WRKDIR}
# doesn't exist.

show-all-${g}: .PHONY
	@echo "${g}:"
.  for c in ${_SHOW_ALL_CATEGORIES}
.    for v in ${${c}.${g}}
.      if (${v:M*_ENV}			\
	|| ${v:M*_ENV.*})

# multi-valued variables, values are sorted
	${RUN}								\
	if ${!defined(${v}) :? true : false}; then			\
	  printf '  %s\t%s (undefined)\n' ${_LABEL.${c}} ${v:Q};	\
	elif value=${${v}:U:M*:Q} && test "x$$value" = "x"; then	\
	  printf '  %s\t%s = # empty\n' ${_LABEL.${c}} ${v:Q};		\
	else								\
	  printf '  %s\t%s (sorted) = \\\n' ${_LABEL.${c}} ${v:Q};	\
	  printf '  \t\t%s \\\n' ${${v}:O:@x@${x:Q}@};			\
	  printf '  \t\t# end of %s\n' ${v:Q};				\
	fi

.      elif (${v:M*_ARGS}		\
	|| ${v:M*_ARGS.*}		\
	|| ${v:M*_CMD}			\
	|| ${v:M*_CMD_DEFAULT}		\
	|| ${v:M*_SKIP}			\
	|| ${v:MMASTER_SITE*}		\
	|| ${v:MSUBST_FILES.*}		\
	|| ${v:MSUBST_SED.*}		\
	|| ${v:MSUBST_FILTER_CMD.*}	\
	|| ${v:M*_SUBST})

# multi-valued variables, preserving original order
	${RUN}								\
	if ${!defined(${v}) :? true : false}; then			\
	  printf '  %s\t%s (undefined)\n' ${_LABEL.${c}} ${v:Q};	\
	elif value=${${v}:U:M*:Q} && test "x$$value" = "x"; then	\
	  printf '  %s\t%s = # empty\n' ${_LABEL.${c}} ${v:Q};		\
	else								\
	  printf '  %s\t%s = \\\n' ${_LABEL.${c}} ${v:Q};		\
	  printf '  \t\t%s \\\n' ${${v}:@x@${x:Q}@};			\
	  printf '  \t\t# end of %s\n' ${v:Q};				\
	fi

.      else

# single-valued variables
	${RUN}								\
	if ${!defined(${v}) :? true : false}; then			\
	  printf '  %s\t%s (undefined)\n' ${_LABEL.${c}} ${v:Q};	\
	elif value=${${v}:U:Q} && test "x$$value" = "x"; then		\
	  printf '  %s\t%s = # empty\n' ${_LABEL.${c}} ${v:Q};		\
	else								\
	  printf '  %s\t%s = %s\n' ${_LABEL.${c}} ${v:Q} "$$value";	\
	fi

.      endif
.    endfor
.  endfor
	${RUN} printf '\n'
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

