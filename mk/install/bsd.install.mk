# $NetBSD: bsd.install.mk,v 1.17 2019/05/07 19:36:44 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to installing packages.
#
# The following are the "public" targets provided this module:
#
#    install, stage-install, deinstall, reinstall, replace, undo-replace
#
# The following targets may be overridden in a package Makefile:
#
#    pre-install, do-install, post-install
#

_COOKIE.install=	${WRKDIR}/.install_done

######################################################################
### install (PUBLIC)
######################################################################
### install is a public target to install the package by depending
### on stage-package-install or package-install. The difference is
### a package is created in the public PACKAGES directory.
###
.PHONY: install
.if ${_KEEP_BIN_PKGS} == "no"
install: stage-package-install
.else
install: package-install
.endif

######################################################################
### stage-install (PUBLIC)
######################################################################
### stage-install is a public target to install the package to
### to ${DESTDIR}${PREFIX}.
###
.PHONY: stage-install
.if !defined(NO_INSTALL)
.  include "install.mk"
.else
.  if exists(${_COOKIE.install}) && !${_CLEANING}
stage-install:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
stage-install: ${_PKGSRC_BUILD_TARGETS} install-cookie
.  else
stage-install: barrier
.  endif
.endif

.include "deinstall.mk"
.include "replace.mk"

######################################################################
### install-cookie (PRIVATE)
######################################################################
### install-cookie creates the "install" cookie file.
###
.PHONY: install-cookie
install-cookie:
	${RUN} [ ! -f ${_COOKIE.install} ]
	${RUN} ${MKDIR} ${_COOKIE.install:H}
	${RUN} ${ECHO} ${PKGNAME} > ${_COOKIE.install}
