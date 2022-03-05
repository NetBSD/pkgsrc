# $NetBSD: Makefile,v 1.44 2022/03/05 12:19:41 tnn Exp $

DISTNAME=	babl-0.1.90
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/babl/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99

MESON_ARGS+=	-Dwith-docs=false
MESON_ARGS+=	-Denable-gir=false

PKGCONFIG_OVERRIDE+=	babl.pc.in

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		Darwin not_Darwin
.if ${OPSYS} == "Darwin"
PLIST.Darwin=		yes
PLIST_SUBST+=		SOEXT="dylib"
.else
PLIST.not_Darwin=	yes
PLIST_SUBST+=		SOEXT="so"
.endif

PLIST_VARS+=		x86_64
.if ${MACHINE_ARCH} == "x86_64"
PLIST.x86_64=		yes
.endif

# Apply removals to post-wrapper transformed arguments.
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,babl.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,babl.map

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
