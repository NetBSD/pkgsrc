# $NetBSD: Makefile,v 1.16 2026/11/08 13:55:09 ryoon Exp $

DISTNAME=		metis-5.2.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=KarypisLab/}
GITHUB_PROJECT=		METIS
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/KarypisLab/METIS
COMMENT=		Unstructured graph partitioning and sparse matrix ordering system
LICENSE=		apache-2.0

USE_TOOLS+=		gmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

CMAKE_CONFIGURE_ARGS+=	-DSHARED=ON

LDFLAGS+=	-L${BUILDLINK_PREFIX.metis}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.metis}/lib
LDFLAGS+=	-lGKlib

pre-configure:
	cd ${WRKSRC} && \
	make config shared=1 cc=gcc prefix=${PREFIX}

.include "../../devel/cmake/build.mk"
.include "../../devel/gklib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
