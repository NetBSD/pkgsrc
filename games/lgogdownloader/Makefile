# $NetBSD: Makefile,v 1.49 2020/05/07 18:21:15 wiz Exp $

DISTNAME=	lgogdownloader-3.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Sude-/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Sude-/lgogdownloader
COMMENT=	Download games from GOG
LICENSE=	public-domain # actually, dwtfywtpl

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
.endif

CMAKE_ARGS+=	-DJSONCPP_INCLUDE_DIR=${BUILDLINK_DIR}/include/json

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../www/htmlcxx/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
