# $NetBSD: Makefile,v 1.45 2024/12/27 08:19:22 wiz Exp $

DISTNAME=	lv2-1.18.10
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	https://lv2plug.in/spec/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lv2plug.in/
COMMENT=	Open standard for audio plugins, used by hundreds of plugins
LICENSE=	isc

PLIST_SRC+=	${PLIST_SRC_DFLT}

USE_TOOLS+=	pkg-config

# header-only-library, so not needed
#PKGCONFIG_OVERRIDE+=		output/meson-private/lv2.pc
#PKGCONFIG_OVERRIDE_STAGE=	post-configure

REPLACE_PYTHON+=	lv2specgen/lv2specgen.py
REPLACE_PYTHON+=	scripts/lv2_build_index.py

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

.include "options.mk"

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.10
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2++=	gtk2+>=2.18.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
