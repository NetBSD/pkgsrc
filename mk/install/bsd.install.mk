# $NetBSD: bsd.install.mk,v 1.9 2006/07/22 16:31:35 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to installing packages.
#
# The following are the "public" targets provided this module:
#
#    install, deinstall, reinstall, replace, undo-replace
#
# The following targets may be overridden in a package Makefile:
#
#    pre-install, do-install, post-install
#

_COOKIE.install=	${WRKDIR}/.install_done

######################################################################
### install (PUBLIC)
######################################################################
### install is a public target to install the package.
###
.PHONY: install
.if !defined(NO_INSTALL)
.  include "${PKGSRCDIR}/mk/install/install.mk"
.elif !target(install)
.  if exists(${_COOKIE.install})
install:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
install: ${_PKGSRC_BUILD_TARGETS} install-cookie
.  else
install: barrier
.  endif
.endif

.include "${PKGSRCDIR}/mk/install/deinstall.mk"
.include "${PKGSRCDIR}/mk/install/replace.mk"

######################################################################
### install-cookie (PRIVATE)
######################################################################
### install-cookie creates the "install" cookie file.
###
.PHONY: install-cookie
install-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} ! -f ${_COOKIE.install} || ${FALSE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_COOKIE.install:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} > ${_COOKIE.install}
