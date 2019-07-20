# $NetBSD: Makefile,v 1.26 2019/07/20 22:46:03 wiz Exp $

GITHUB_TAG=	V4.4.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	libzrtpcpp${DISTNAME:S/V/-/1}
PKGREVISION=	15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wernerd/}
GITHUB_PROJECT=	ZRTPCPP
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.gnutelephony.org/index.php/GNU_ZRTP
COMMENT=	ZRTP extension for GNU ccRTP
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_PKGLOCALEDIR=	yes
GCC_REQD+=		4.7
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
PKG_DESTDIR_SUPPORT=	destdir
CMAKE_ARGS+=		-DLIBDIRNAME=lib

.include "options.mk"

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8
#BUILDLINK_DEPMETHOD.openssl=	build
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
