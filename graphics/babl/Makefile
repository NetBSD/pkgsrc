# $NetBSD: Makefile,v 1.36 2020/06/15 10:55:02 ryoon Exp $

DISTNAME=	babl-0.1.78
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/babl/0.1/
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
PLIST_SUBST+=  		SOEXT="dylib"
.else
PLIST.not_Darwin=	yes
PLIST_SUBST+=  		SOEXT="so"
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
