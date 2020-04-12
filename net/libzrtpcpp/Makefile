# $NetBSD: Makefile,v 1.30 2020/04/12 08:28:04 adam Exp $

GITHUB_TAG=	V4.4.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	libzrtpcpp${DISTNAME:S/V/-/1}
PKGREVISION=	18
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

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
