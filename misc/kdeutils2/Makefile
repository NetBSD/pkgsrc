# $NetBSD: Makefile,v 1.11 2002/09/04 14:47:38 agc Exp $

DISTNAME=	kdeutils-2.2.2
PKGREVISION=	1
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif

post-install:
	${CHMOD} -s ${PREFIX}/bin/efax

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
