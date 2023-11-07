# $NetBSD: Makefile,v 1.3 2023/11/07 19:50:35 nros Exp $

DISTNAME=	minizip-ng-4.0.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=zlib-ng/}
GITHUB_PROJECT=	minizip-ng
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/zlib-ng/minizip-ng/
COMMENT=	Zip manipulation library written in C
LICENSE=	zlib

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	minizip.pc.cmakein

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=YES
CMAKE_CONFIGURE_ARGS+=	-DMZ_BZIP2=YES
CMAKE_CONFIGURE_ARGS+=	-DMZ_LZMA=YES
CMAKE_CONFIGURE_ARGS+=	-DMZ_ZSTD=YES
CMAKE_CONFIGURE_ARGS+=	-DMZ_COMPAT=NO

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
