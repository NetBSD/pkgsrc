# $NetBSD: Makefile,v 1.9 2002/10/07 07:44:23 jlam Exp $

DISTNAME=	kdeutils-3.0.3
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

_KDE_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4755
SPECIAL_PERMS+=	${PREFIX}/bin/efax ${_KDE_SETUID_ROOT}

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
