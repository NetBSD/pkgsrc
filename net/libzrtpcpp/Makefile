# $NetBSD: Makefile,v 1.4 2014/01/01 11:52:02 wiz Exp $

DISTNAME=	libzrtpcpp-2.3.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=ccrtp/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://wiki.gnutelephony.org/
COMMENT=	ZRTP extension for GNU ccRTP
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
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
