# $NetBSD: Makefile,v 1.35 2004/03/26 02:27:46 wiz Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
PKGREVISION=	1
COMMENT=	Utilities for the KDE integrated X11 desktop

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	gtar-base>=1.13.25:../../archivers/gtar-base

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

EVAL_PREFIX+=		PREFIX.gtar=gtar
PREFIX.gtar_DEFAULT=	${LOCALBASE}
CPPFLAGS+=		-DARK_TAR=\"\\\"${PREFIX.gtar}/bin/${GNU_PROGRAM_PREFIX}tar\\\"\"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
