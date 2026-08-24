# $NetBSD: Makefile,v 1.117 2026/08/24 08:42:27 adam Exp $

DISTNAME=	amule-3.0.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=amule-project/}

MAINTAINER=	tripledes@eslack.org
HOMEPAGE=	https://www.amule.org/
COMMENT=	Another Emule P2P client
LICENSE=	gnu-gpl-v2

CONFLICTS=		xmule-[0-9]*

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF # needs some options
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NLS=ON

.include "options.mk"

REPLACE_PERL+=	src/libs/ec/file_generator.pl
REPLACE_PERL+=	src/utils/scripts/kadnodescreate.pl
REPLACE_PERL+=	src/utils/scripts/stats.pl
REPLACE_PERL+=	src/utils/scripts/mldonkey_importer.pl
REPLACE_PERL+=	src/utils/xas/xas.pl

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
