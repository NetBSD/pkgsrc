# $NetBSD: Makefile,v 1.21 1998/11/13 00:58:23 frueauf Exp $
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

DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png

CONFLICTS=	netpbm-94.3.1

WRKSRC=		${WRKDIR}/netpbm
MAKE_ENV +=	PREFIX=${PREFIX} INSTALL_MAN="${INSTALL_MAN}"

post-extract:
# make sure our TIFF library is used
	${RM} -rf ${WRKSRC}/libtiff
# move updates into source tree
	cd ${WRKSRC};\
	${MV} ../*pcx*.? ppm;\
	${MV} ../*rle*.? ../*png*.? pnm

post-install:
.for PBMLIB in pbm pgm pnm ppm
	${INSTALL_DATA} ${WRKSRC}/${PBMLIB}/lib${PBMLIB}.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/${PBMLIB}/${PBMLIB}.h ${PREFIX}/include
.endfor

.include "../../mk/bsd.pkg.mk"
