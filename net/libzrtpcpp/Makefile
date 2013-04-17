# $NetBSD: Makefile,v 1.1 2013/04/17 00:55:35 rodent Exp $

DISTNAME=	libzrtpcpp-2.3.2
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
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ucommon/buildlink3.mk"
.include "../../net/ccrtp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
