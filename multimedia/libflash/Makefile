# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 13:34:45 jmmv Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	4
COMMENT=	Open source Flash(tm) library

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO="${LIBOSSAUDIO}"
MAKE_ENV+=	LIBSTDCPP=-lstdc++

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
