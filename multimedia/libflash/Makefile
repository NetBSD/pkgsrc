# $NetBSD: Makefile,v 1.13 2013/04/06 15:46:37 rodent Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	9
COMMENT=	Open source Flash(tm) library

USE_LIBTOOL=	yes
BUILD_DIRS=	Lib
MAKE_ENV+=	LIBOSSAUDIO=${LIBOSSAUDIO:Q}
MAKE_ENV+=	LIBSTDCPP=-lstdc++

INSTALLATION_DIRS+=	lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
