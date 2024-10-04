# $NetBSD: Makefile,v 1.31 2024/10/04 03:49:13 ryoon Exp $

DISTNAME=	innoextract-1.9
PKGREVISION=	11
CATEGORIES=	archivers
MASTER_SITES=	https://constexpr.org/innoextract/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://constexpr.org/innoextract/
COMMENT=	Tool to unpack installers created by Inno Setup
LICENSE=	zlib

USE_CXX_FEATURES=	filesystem
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}
CMAKE_CONFIGURE_ARGS+=	-DSET_OPTIMIZATION_FLAGS=OFF

.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
