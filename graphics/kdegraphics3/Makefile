# $NetBSD: Makefile,v 1.37.4.1 2004/10/25 21:25:25 agc Exp $

DISTNAME=	kdegraphics-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	Graphics programs for the KDE integrated X11 desktop

PATCHFILES=	post-3.2.3-kdegraphics.diff
SITES_post-3.2.3-kdegraphics.diff=	ftp://ftp.kde.org/pub/kde/security_patches/

.include "../../meta-pkgs/kde3/Makefile.kde3"

#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1

BUILDLINK_DEPENDS.lcms=	lcms>=1.12

CONFIGURE_ARGS+=	--without-kamera	# requires gPhoto2, gpio
CONFIGURE_ARGS+=	--with-imlib-config=${X11PREFIX}/bin

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && !exists(${X11BASE}/lib/libXxf86vm.so)
PLIST_SUBST+=		KGAMMA_SUFFIX="a"
.else
PLIST_SUBST+=		KGAMMA_SUFFIX="so"
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
