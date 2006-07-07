# $NetBSD: bsd.configure.mk,v 1.5 2006/07/07 13:39:52 jlam Exp $
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
.if !defined(NO_CONFIGURE)
.  include "${PKGSRCDIR}/mk/configure/configure.mk"
.elif !target(configure)
.  if exists(${_CONFIGURE_COOKIE})
configure:
	@${DO_NADA}
.  elif exists(${_BARRIER_COOKIE})
configure: wrapper configure-cookie
.  else
configure: barrier
.  endif
.endif

######################################################################
### configure-cookie (PRIVATE)
######################################################################
### configure-cookie creates the "configure" cookie file.
###
.PHONY: configure-cookie
configure-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} ! -f ${_CONFIGURE_COOKIE} || ${FALSE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_CONFIGURE_COOKIE:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} > ${_CONFIGURE_COOKIE}
