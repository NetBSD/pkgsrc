# $NetBSD: Makefile,v 1.17 1998/07/04 04:18:26 mycroft Exp $
#

DISTNAME=	netpbm
PKGNAME=	netpbm-19940301
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wustl.edu//graphics/graphics/packages/NetPBM/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/netpbm/ \
		ftp://ftp.informatik.uni-oldenburg.de/pub/grafik/png/applications/
DISTFILES=	netpbm-1mar1994.tar.gz \
		pcxtoppm.tar.gz \
		rletopnm.tar.gz \
		pnmtopng-2.36.tar.gz

MAINTAINER=	tron@netbsd.org

CONFLICTS=	netpbm-94.3.1

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png

WRKSRC=		${WRKDIR}/netpbm
MAKE_ENV +=	PREFIX=${PREFIX} INSTALL_MAN="${INSTALL_MAN}"

post-extract:
# make sure our TIFF library is used
	${RM} -rf ${WRKSRC}/libtiff
# move updates into source tree
	cd ${WRKSRC};\
	${MV} ../*pcx*.? ppm;\
	${MV} ../*rle*.? ../*png*.? pnm

.include "../../mk/bsd.pkg.mk"
