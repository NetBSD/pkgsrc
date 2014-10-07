# $NetBSD: Makefile,v 1.3 2014/10/07 16:47:11 adam Exp $

DISTNAME=	leptonica-1.71
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.leptonica.org/source/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.leptonica.org/
COMMENT=	Software for image processing and image analysis applications
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

# The presence of fmemopen() assumes open_memstream() is also available,
# which is wrong on platforms other than Linux.
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		ac_cv_func_fmemopen=no
.endif

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
