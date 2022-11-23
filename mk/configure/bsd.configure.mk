# $NetBSD: bsd.configure.mk,v 1.13 2022/11/23 13:30:38 jperkin Exp $
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
.  include "configure.mk"
.elif !target(configure)
.  if exists(${_COOKIE.configure}) && !${_CLEANING}
configure:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
configure: wrapper _configure-cookie
.  else
configure: barrier
.  endif
.endif

# Creates the "configure" cookie file.
_configure-cookie: .PHONY
	${RUN}								\
	[ ! -f ${_COOKIE.configure} ];					\
	${TEST} -d ${_COOKIE.configure:H} || ${MKDIR} ${_COOKIE.configure:H}; \
	${ECHO} ${PKGNAME} > ${_COOKIE.configure}
