# $NetBSD: Makefile,v 1.15 2023/11/03 10:15:47 nros Exp $

DISTNAME=	libmsn-4.2.1
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmsn/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libmsn
COMMENT=	Library for connecting to Microsoft's MSN Messenger service
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

# fix build with compilers that default to c++ 17 and above
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_STANDARD=98
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_STANDARD_REQUIRED:BOOL=ON

PKGCONFIG_OVERRIDE+=	libmsn.pc.cmake

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/cmake/build.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
