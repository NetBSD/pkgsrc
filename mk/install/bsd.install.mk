# $NetBSD: bsd.install.mk,v 1.13 2010/02/24 22:53:34 joerg Exp $
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
### install is a public target to install the package either by
### depending on stage-install (_USE_DESTDIR=no) or package-install
### (_USE_DESTDIR!=no).
###
.PHONY: install
.if ${_USE_DESTDIR} == "no"
install: stage-install
.else
install: package-install
.endif

######################################################################
### stage-install (PUBLIC)
######################################################################
### stage-install is a public target to install the package to
### ${PREFIX} (_USE_DESTDIR=no) or to ${DESTDIR}${PREFIX}
### (_USE_DESTDIR!=no)
###
.PHONY: stage-install
.if !defined(NO_INSTALL)
.  include "install.mk"
.else
.  if exists(${_COOKIE.install})
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
