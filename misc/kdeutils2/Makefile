# $NetBSD: Makefile,v 1.19 2004/05/02 03:42:19 snj Exp $

DISTNAME=	kdeutils-2.2.2
PKGREVISION=	6
COMMENT=	Utilities for the KDE integrated X11 desktop

CONFLICTS=	efax-[0-9]*

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK3=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif

post-install:
	${CHMOD} -s ${PREFIX}/bin/efax

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
