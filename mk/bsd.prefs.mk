# $NetBSD: bsd.prefs.mk,v 1.5 1999/05/23 22:10:01 tv Exp $
#
# Make file, included to get the site preferences, if any.  Should
# only be included by package Makefiles before any .if defined()
# statements, to make sure any variables defined in /etc/mk.conf or
# $MAKECONF are used.

# Do not recursively include mk.conf, redefine OPSYS, include bsd.own.mk, etc.
.ifndef BSD_PKG_MK

# Let people know this is bsd.pkg.mk, so they can set up their
# /etc/mk.conf accordingly  
BSD_PKG_MK=1 

.if !defined(OPSYS)
OPSYS!= /usr/bin/uname -s
.endif

# Don't complain about environment settings on recursive makes.
__PREFIX_SET__=${PREFIX}

.if (${OPSYS} == "NetBSD")
NEED_OWN_INSTALL_TARGET=	no
.include <bsd.own.mk>
SHAREOWN = ${DOCOWN}
SHAREGRP = ${DOCGRP}
SHAREMODE = ${DOCMODE}
.elif (${OPSYS} == "SunOS")
NEED_OWN_INSTALL_TARGET=	no
.include <bsd.own.mk>
SHAREOWN = ${DOCOWN}
SHAREGRP = ${DOCGRP}
SHAREMODE = ${DOCMODE}
.elif (${OPSYS} == "OpenBSD")
.include <bsd.own.mk>
MAKE_ENV+=	EXTRA_SYS_MK_INCLUDES="<bsd.own.mk>"
.endif

.if defined(PREFIX) && (${PREFIX} != ${__PREFIX_SET__})
.BEGIN:
	@${ECHO_MSG} "You can NOT set PREFIX manually or in mk.conf.  Set LOCALBASE or X11BASE"
	@${ECHO_MSG} "depending on your needs.  See the pkg system documentation for more info."
	@${FALSE}
.endif

.endif
