# $NetBSD: bsd.configure.mk,v 1.2 2006/07/05 09:08:35 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to configuring packages for building.
#
# The following are the "public" targets provided by this module:
#
#    configure
#
# The following targets may be overridden in a package Makefile:
#
#    pre-configure, do-configure, post-configure
#

_CONFIGURE_COOKIE=	${WRKDIR}/.configure_done

######################################################################
### configure (PUBLIC)
######################################################################
### configure is a public target to configure the software for building.
###
.PHONY: configure
.if defined(NO_CONFIGURE)
.  if !target(configure)
configure: patch configure-cookie
.  endif
.else
.  include "${PKGSRCDIR}/mk/configure/configure.mk"
.endif

######################################################################
### configure-cookie (PRIVATE)
######################################################################
### configure-cookie creates the "configure" cookie file.
###
.PHONY: configure-cookie
configure-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_CONFIGURE_COOKIE:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} > ${_CONFIGURE_COOKIE}
