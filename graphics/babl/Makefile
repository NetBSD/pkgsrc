# $NetBSD: Makefile,v 1.48 2022/07/10 20:23:38 wiz Exp $

DISTNAME=	babl-0.1.92
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


PKG_OPTIONS_VAR=	PKG_OPTIONS.babl
PKG_SUPPORTED_OPTIONS=
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
PKG_SUPPORTED_OPTIONS+=	mmx
.endif

.include "../../mk/compiler.mk"

.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") \
	&& empty(CC_VERSION:Mgcc-7.*)
PKG_SUGGESTED_OPTIONS=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
MESON_ARGS+=	-Denable-mmx=true
.else
MESON_ARGS+=	-Denable-mmx=false
.endif

# Apply removals to post-wrapper transformed arguments.
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,babl.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,babl.map

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/babl

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
