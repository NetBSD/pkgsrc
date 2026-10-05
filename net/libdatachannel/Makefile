# $NetBSD: Makefile,v 1.1 2026/10/05 13:18:20 ktnb Exp $

DISTNAME=	libdatachannel-0.24.6
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=paullouisageneau/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/paullouisageneau/libdatachannel/
COMMENT=	C/C++ WebRTC network library
LICENSE=	mpl-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DPREFER_SYSTEM_LIB=TRUE
CMAKE_CONFIGURE_ARGS+=	-DUSE_NICE=TRUE

.include "../../devel/cmake/build.mk"
.include "../../devel/plog/buildlink3.mk"
.include "../../comms/srtp/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
.include "../../net/usrsctp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
