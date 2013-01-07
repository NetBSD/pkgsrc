# $NetBSD: Makefile,v 1.3 2013/01/07 13:00:02 adam Exp $

DISTNAME=	openjpeg-1.5.1
PKGNAME=	${DISTNAME:S/openjpeg/openjpeg15/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://openjpeg.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openjpeg.org/
COMMENT=	JPEG 2000 library
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--disable-doc
GNU_CONFIGURE=		yes

CFLAGS+=	-DHAVE_POSIX_MEMALIGN

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
