# $NetBSD: Makefile,v 1.77 2025/01/31 15:52:53 wiz Exp $

DISTNAME=	openbabel-3.1.1
PKGREVISION=	34
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=openbabel/}
GITHUB_TAG=	openbabel-${PKGVERSION_NOREV:S/./-/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openbabel.org/
COMMENT=	Chemistry file translation program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c gnu++11
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	openbabel-3.pc.cmake

.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH:Q}

.include "../../devel/cmake/build.mk"
.include "../../biology/coordgenlibs/buildlink3.mk"
.include "../../biology/maeparser/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
