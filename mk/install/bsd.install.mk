# $NetBSD: bsd.install.mk,v 1.2 2006/06/05 17:41:11 jlam Exp $
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

_INSTALL_COOKIE=	${WRKDIR}/.install_done

######################################################################
### install (PUBLIC)
######################################################################
### install is a public target to install the package.
###
.if defined(NO_INSTALL)
.PHONY: install
.  if !target(install)
install: ${_PKGSRC_BUILD_TARGETS} install-cookie
.  endif
.else
.  include "${PKGSRCDIR}/mk/install/install.mk"
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
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} >> ${_INSTALL_COOKIE}

