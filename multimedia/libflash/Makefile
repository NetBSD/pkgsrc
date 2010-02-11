# $NetBSD: Makefile,v 1.9 2010/02/11 20:01:50 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	8
COMMENT=	Open source Flash(tm) library

USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=	LIBSTDCPP=-lstdc++

INSTALLATION_DIRS+=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
