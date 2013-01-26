# $NetBSD: Makefile,v 1.12 2013/01/26 21:36:38 adam Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	9
COMMENT=	Open source Flash(tm) library

USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=	LIBSTDCPP=-lstdc++

INSTALLATION_DIRS+=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
