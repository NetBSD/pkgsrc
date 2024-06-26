# $NetBSD: Makefile,v 1.5 2024/06/26 16:16:26 adam Exp $

DISTNAME=	minizip-ng-4.0.7
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=zlib-ng/}
GITHUB_PROJECT=	minizip-ng
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/zlib-ng/minizip-ng
COMMENT=	Zip manipulation library written in C
LICENSE=	zlib

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	minizip.pc.cmakein

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=YES
CMAKE_CONFIGURE_ARGS+=	-DMZ_COMPAT=NO

PLIST_VARS+=	libcomp zlib

.include "../../mk/bsd.prefs.mk"
# On Darwin, libcompression is preferred over zlib, see CMakeLists.txt
.if ${OPSYS} == "Darwin"
PLIST.libcomp=	yes
.else
PLIST.zlib=	yes
.include "../../archivers/zlib-ng/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
