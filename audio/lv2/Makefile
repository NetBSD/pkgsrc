# $NetBSD: Makefile,v 1.31 2022/06/30 11:18:02 nia Exp $

DISTNAME=	lv2-1.18.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://lv2plug.in/spec/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lv2plug.in/
COMMENT=	Open standard for audio plugins, used by hundreds of plugins
LICENSE=	isc

PLIST_SRC+=	${PLIST_SRC_DFLT}

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lv2/lv2plug.in/ns/lv2core/lv2core.pc.in
PKGCONFIG_OVERRIDE+=	lv2.pc.in

REPLACE_PYTHON+=	lv2specgen/lv2specgen.py

PYTHON_VERSIONED_DEPENDENCIES=	markdown pygments

.include "options.mk"

WAF_ARGS+=	${BUILD_DEBUG} ${BUILD_DOC} ${BUILD_TESTS} ${BUILD_VALGRIND}
WAF_ARGS+=	--copy-headers

.include "../../devel/waf/waf.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.10
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2++=	gtk2+>=2.18.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
