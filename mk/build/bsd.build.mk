# $NetBSD: bsd.build.mk,v 1.12 2017/06/01 02:15:10 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to building sources for a package.
#
# The following are the "public" targets provided by this module:
#
#    build, test
#
# The following targets may be overridden in a package Makefile:
#
#    pre-build, do-build, post-build
#    pre-test,  do-test,  post-test
#
# Package-settable variables:
#
# NO_BUILD
#	When defined, the whole build phase is skipped. That includes
#	any substitutions that have one of {pre,do,post}-build as their
#	SUBST_STAGE.
#

_COOKIE.build=	${WRKDIR}/.build_done
_COOKIE.test=	${WRKDIR}/.test_done

######################################################################
### build (PUBLIC)
######################################################################
### build is a public target to build the sources for the package.
###
.PHONY: build
.if !defined(NO_BUILD)
.  include "build.mk"
.elif !target(build)
.  if exists(${_COOKIE.build})
build:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
.    if ${_USE_NEW_PKGINSTALL:Uno} != "no"
build: configure build-cookie
.    else
build: configure build-cookie pkginstall
.    endif
.  else
build: barrier
.  endif
.endif

.include "test.mk"

######################################################################
### build-cookie (PRIVATE)
######################################################################
### build-cookie creates the "build" cookie file.
###
.PHONY: build-cookie
build-cookie:
	${RUN}${TEST} ! -f ${_COOKIE.build} || ${FALSE}
	${RUN}${MKDIR} ${_COOKIE.build:H}
	${RUN}${ECHO} ${PKGNAME} > ${_COOKIE.build}
