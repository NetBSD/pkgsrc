# $NetBSD: Makefile,v 1.5 2014/01/10 02:58:51 rodent Exp $

DISTNAME=	V4.1.2
PKGNAME=	libzrtpcpp${DISTNAME:S/V/-/1}
CATEGORIES=	net
MASTER_SITES=	https://github.com/wernerd/ZRTPCPP/archive/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://wiki.gnutelephony.org/
COMMENT=	ZRTP extension for GNU ccRTP
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/ZRTPCPP-${PKGVERSION_NOREV}

USE_PKGLOCALEDIR=	yes
GCC_REQD+=		4.7
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
USE_CMAKE=		yes
PKG_DESTDIR_SUPPORT=	destdir
CMAKE_ARGS+=		-DLIBDIRNAME=lib

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7i
BUILDLINK_DEPMETHOD.openssl=	build
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
