# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:16 joerg Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	6
COMMENT=	Open source Flash(tm) library

USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=	LIBSTDCPP=-lstdc++

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
