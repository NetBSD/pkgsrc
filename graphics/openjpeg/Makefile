# $NetBSD: Makefile,v 1.6 2012/12/06 17:09:18 adam Exp $

DISTNAME=	openjpeg-2.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://openjpeg.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openjpeg.org/
COMMENT=	JPEG 2000 library
LICENSE=	2-clause-bsd

USE_CMAKE=		yes

CFLAGS+=	-DHAVE_POSIX_MEMALIGN

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
