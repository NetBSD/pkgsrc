# $NetBSD: Makefile,v 1.36 2004/04/05 09:31:30 mrg Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
PKGREVISION=	1
COMMENT=	Utilities for the KDE integrated X11 desktop

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.6*) || !empty(MACHINE_PLATFORM:MNetBSD-[2-9]*)
CPPFLAGS+=		-DARK_TAR=\"\\\"/usr/bin/tar\\\"\"
.else
DEPENDS+=	gtar-base>=1.13.25:../../archivers/gtar-base

EVAL_PREFIX+=		PREFIX.gtar=gtar
PREFIX.gtar_DEFAULT=	${LOCALBASE}
CPPFLAGS+=		-DARK_TAR=\"\\\"${PREFIX.gtar}/bin/${GNU_PROGRAM_PREFIX}tar\\\"\"
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
