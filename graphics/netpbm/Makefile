# $NetBSD: Makefile,v 1.23 1999/01/10 23:52:15 tron Exp $
#

DISTNAME=	netpbm
PKGNAME=	netpbm-19940301
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wustl.edu/graphics/graphics/packages/NetPBM/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/netpbm/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/grafik/png/applications/
DISTFILES=	netpbm-1mar1994.tar.gz \
		pcxtoppm.tar.gz \
		rletopnm.tar.gz \
		pnmtopng-2.37.1.tar.gz

MAINTAINER=	tron@netbsd.org

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png

CONFLICTS=	netpbm-*

WRKSRC=		${WRKDIR}/netpbm
MAKE_ENV +=	PREFIX=${PREFIX} MANCP="${INSTALL_MAN}"
NO_CONFIGURE=	yes

post-extract:
# move updates into source tree
	cd ${WRKSRC}; \
	${MV} ../*pcx*.? ppm; \
	${MV} ../*rle*.? ../*png*.? pnm;

.include "../../mk/bsd.pkg.mk"
