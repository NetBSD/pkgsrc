# $NetBSD: Makefile,v 1.5 2000/06/01 11:23:40 rh Exp $
#

DISTNAME=		pdflib-3.0
CATEGORIES=		print
MASTER_SITES=		http://www.pdflib.com/pdflib/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pdflib.com/pdflib/index.html

DEPENDS+=	tiff-3.5.5:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-*:../../graphics/png
#DEPENDS+=	zlib-1.1.3:../../devel/zlib

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-tifflib=${PREFIX} \
			--with-pnglib=${PREFIX}
USE_PKGLIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
