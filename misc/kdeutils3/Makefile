# $NetBSD: Makefile,v 1.19 2003/05/02 11:55:55 wiz Exp $

DISTNAME=	kdeutils-3.1.1
PKGREVISION=	1
COMMENT=	Utilities for the KDE integrated X11 desktop

CONFLICTS=	efax-[0-9]*

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"


.include "../../mk/bsd.prefs.mk"

_KDE_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4755
SPECIAL_PERMS+=	${PREFIX}/bin/efax ${_KDE_SETUID_ROOT}

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

FOO_MAIN_FILES= \
	kcalc/kcalc_main.cpp \
	kedit/kedit_main.cpp \
	klaptopdaemon/klaptopdaemon_main.cpp

.include "../../x11/kde3/Makefile.foo_main"

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
