# $NetBSD: Makefile,v 1.5.10.1 2014/04/12 17:14:38 tron Exp $

DISTNAME=	openjpeg-1.5.2
PKGNAME=	${DISTNAME:S/openjpeg/openjpeg15/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjpeg.mirror/}

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
