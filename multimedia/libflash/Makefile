# $NetBSD: Makefile,v 1.7 2009/08/26 19:56:39 sno Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	7
COMMENT=	Open source Flash(tm) library

USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=	LIBSTDCPP=-lstdc++

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
