# $NetBSD: Makefile,v 1.43 2020/11/04 19:54:12 bsiegert Exp $
#

GITHUB_PROJECT=	openbabel
DISTNAME=	openbabel-${RELVERSION:S/-/./g}
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=openbabel/}
GITHUB_TAG=	${PKGBASE}-${RELVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openbabel.org/
COMMENT=	Chemistry file translation program
LICENSE=	gnu-gpl-v2

RELVERSION=	3-1-1

USE_LANGUAGES=	c gnu++11
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	openbabel-3.pc.cmake

.include "options.mk"

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH:Q}

post-extract:
	${MKDIR} ${WRKDIR}/build

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
