# $NetBSD: Makefile,v 1.72 2024/05/16 06:14:55 wiz Exp $

DISTNAME=	lgogdownloader-3.12
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sude-/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Sude-/lgogdownloader
COMMENT=	Download games from GOG
LICENSE=	public-domain # actually, dwtfywtpl

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DJSONCPP_INCLUDE_DIR=${BUILDLINK_DIR}/include/json

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../www/htmlcxx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
