# $NetBSD: Makefile,v 1.7 2003/01/30 12:22:47 jlam Exp $
#

.include "Makefile.common"

PKGNAME=	lib${DISTNAME}
PKGREVISION=	4
COMMENT=	open source Flash(tm) library

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
BUILD_DIRS=	${WRKSRC}/Lib
MAKE_ENV+=	LIBOSSAUDIO="${LIBOSSAUDIO}"

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
