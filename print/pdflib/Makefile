# $NetBSD: Makefile,v 1.3 2000/02/03 19:32:59 drochner Exp $
#

DISTNAME=		pdflib-2.01
CATEGORIES=		print
MASTER_SITES=		http://www.pdflib.com/pdflib/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pdflib.com/pdflib/index.html

DEPENDS+=	tiff-3.5.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
#DEPENDS+=	zlib-1.1.3:../../devel/zlib

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../mk/bsd.pkg.mk"
