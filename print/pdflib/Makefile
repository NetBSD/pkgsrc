# $NetBSD: Makefile,v 1.8 2001/02/17 17:51:52 wiz Exp $
#

DISTNAME=		pdflib-3.03
CATEGORIES=		print
MASTER_SITES=		http://www.pdflib.com/pdflib/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pdflib.com/pdflib/index.html
COMMENT=		C library to produce PDF files

DEPENDS+=	tiff-3.5.5:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-*:../../graphics/png

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-tifflib=${PREFIX} \
			--with-pnglib=${PREFIX} \
			--enable-shared-pdflib
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

.include "../../mk/bsd.pkg.mk"
