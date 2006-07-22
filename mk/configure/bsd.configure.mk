# $NetBSD: bsd.configure.mk,v 1.7 2006/07/22 16:31:35 jlam Exp $
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

_COOKIE.configure=	${WRKDIR}/.configure_done

######################################################################
### configure (PUBLIC)
######################################################################
### configure is a public target to configure the software for building.
###
.PHONY: configure
.if !defined(NO_CONFIGURE)
.  include "${PKGSRCDIR}/mk/configure/configure.mk"
.elif !target(configure)
.  if exists(${_COOKIE.configure})
configure:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
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
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} ! -f ${_COOKIE.configure} || ${FALSE}
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_COOKIE.configure:H}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} > ${_COOKIE.configure}
