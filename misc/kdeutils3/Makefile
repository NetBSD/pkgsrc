# $NetBSD: Makefile,v 1.2 2002/07/17 07:54:06 skrll Exp $

DISTNAME=	kdeutils-3.0.2
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS=			-Wl,--export-dynamic

.  if exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.  endif
.endif

post-install:
	${CHMOD} -s ${PREFIX}/bin/efax

.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
