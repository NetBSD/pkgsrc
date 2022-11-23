# $NetBSD: bsd.depends.mk,v 1.33 2022/11/23 13:30:38 jperkin Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to dependencies.
#
# The following are the "public" targets provided by this module:
#
#    depends, bootstrap-depends, install-depends, show-depends
#
# The following variables may be set in a package Makefile:
#
# DEPENDS
#	List of dependencies of the form "pattern:dir" needed by the
#	package at run-time.
#
# BUILD_DEPENDS
#	List of build dependencies of the form "pattern:dir" needed by the
#	package at build-time.  When cross-compiling, build dependencies
#	are `target' packages, i.e. architecture for which the package is
#	built.
#
# TEST_DEPENDS
#	List of test dependencies of the form "pattern:dir" needed by the
#	package at test-time.  When cross-compiling, test dependencies
#	are `native' packages, i.e. architecture where the package is
#	built.
#
# TOOL_DEPENDS
#	List of tool dependencies of the form "pattern:dir" needed by the
#	package at build-time.  When cross-compiling, tool dependencies
#	are `native' packages, i.e. architecture where the package is
#	built.
#
# The following variables may be set by the pkgsrc user:
#
# SKIP_DEPENDS
#	Whether to run the ``depends'' phase.  This is probably only
#	useful for pkgsrc developers.
#
#	Default value: no
#
# Keywords: depends dependencies

SKIP_DEPENDS?=	no

# DEPENDS_TARGET is the target that is invoked to satisfy missing
# dependencies.  This variable is user-settable in /etc/mk.conf.
#
.if !defined(DEPENDS_TARGET)
.  if make(update)
.    if defined(UPDATE_TARGET) && (${UPDATE_TARGET} == "replace")
DEPENDS_TARGET=		${UPDATE_TARGET}
.    else
DEPENDS_TARGET=		update
.    endif
.  elif make(bin-install) || make(su-bin-install)
DEPENDS_TARGET=		bin-install
.  elif make(package) || make(package-install)
DEPENDS_TARGET=		package-install
.  else
DEPENDS_TARGET=		reinstall
.  endif
.endif

######################################################################
### depends (PUBLIC)
######################################################################
### depends is a public target to install missing dependencies for
### the package.
###
.PHONY: depends
.if ${SKIP_DEPENDS:M[Nn][Oo]} != ""
.  include "depends.mk"
.elif !target(depends)
.  if exists(${_COOKIE.depends}) && !${_CLEANING}
depends:
	@${DO_NADA}
.  else
depends: depends-cookie
.  endif
.endif

######################################################################
### bootstrap-depends (PUBLIC, OVERRIDE)
######################################################################
### bootstrap-depends is a public target to install any missing
### dependencies needed during stages before the normal "depends"
### stage.  These dependencies are listed in BOOTSTRAP_DEPENDS.
###
.PHONY: bootstrap-depends
.if !target(bootstrap-depends)
bootstrap-depends:
	@${DO_NADA}
.endif

######################################################################
### install-depends (PUBLIC)
######################################################################
### install-depends is a convenience target that installs all dependencies
### and removes the cookie file afterwards, so that the state of the
### filesystem remains unchanged.
###
### XXX This target is probably not needed and might be removed.
###
.PHONY: install-depends
install-depends: depends depends-clean

######################################################################
### depends-clean (PRIVATE)
######################################################################
### depends-clean removes the state files associated with the "depends"
### target so that "depends" may be re-invoked.
###
depends-clean:
	${RUN}								\
	${RM} -f ${_COOKIE.depends};					\
	${RMDIR} -p ${_COOKIE.depends:H} 2>/dev/null || ${TRUE}

######################################################################
### depends-cookie (PRIVATE, override)
######################################################################
### depends-cookie creates the depends "cookie" state file.  This should
### be overridden per package system format.
###
.PHONY: depends-cookie
depends-cookie:
	${RUN}								\
	${TEST} ! -f ${_COOKIE.depends} || ${FALSE};			\
	${TEST} -d ${_COOKIE.depends:H} || ${MKDIR} ${_COOKIE.depends:H}; \
	${TOUCH} ${TOUCH_ARGS} ${_COOKIE.depends}

# show-depends:
#	Prints the dependencies that need to be installed before this
#	package can be installed.  Each line of the output has the format
#	'dependency:directory', as in DEPENDS and the related variables.
#
#	Command line variables:
#
#	VARNAME
#		DEPENDS, BUILD_DEPENDS, TEST_DEPENDS, or TOOL_DEPENDS.
#
# See also:
#	show-depends-pkgpaths	Prints the PKGPATH of all direct dependencies.
#	show-depends-recursive	Prints the PKGPATH of all direct and
#				indirect dependencies.
#
# Keywords: depends dependencies
show-depends: .PHONY _pkgformat-show-depends
