# $NetBSD: Makefile,v 1.3 2026/01/07 08:47:52 wiz Exp $

DISTNAME=	igraph-${V}
V=		1.0.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=igraph/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://igraph.org/
COMMENT=	Package For Manipulating Undirected And Directed Graphs
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bison cmake pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Git=True
CMAKE_BUILD_DIR=	build

pre-configure:
	@${ECHO} ${V} > ${WRKSRC}/IGRAPH_VERSION

.include "../../devel/cmake/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/glpk/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
