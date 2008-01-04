# $NetBSD: bsd.configure.mk,v 1.11 2008/01/04 01:46:26 rillig Exp $
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
.  if exists(${_COOKIE.configure})
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
	${RUN} [ ! -f ${_COOKIE.configure} ]	# XXX: What's the purpose of this assertion?
	${RUN} ${MKDIR} ${_COOKIE.configure:H}
	${RUN} ${ECHO} ${PKGNAME} > ${_COOKIE.configure}
