# $NetBSD: Makefile,v 1.44 2023/11/08 13:20:30 wiz Exp $

DISTNAME=	libzrtpcpp-4.7.0
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wernerd/}
GITHUB_PROJECT=	ZRTPCPP

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/ccrtp/zrtp.html
COMMENT=	ZRTP extension for GNU ccRTP
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
CMAKE_ARGS+=		-DCCRTP=ON
CMAKE_ARGS+=		-DLIB_SUFFIX=""

CMAKE_USE_GNU_INSTALL_DIRS=	no

PKGCONFIG_OVERRIDE=	libzrtpcpp.pc.cmake

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
