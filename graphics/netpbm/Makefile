# $NetBSD: Makefile,v 1.35 2000/03/21 22:40:54 tron Exp $
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
		pnmtopng-2.37.3.tar.gz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	png>=1.0.6:../../graphics/png

WRKSRC=		${WRKDIR}/netpbm
MAKE_ENV +=	PREFIX=${PREFIX} MANCP="${INSTALL_MAN}"
NO_CONFIGURE=	yes

post-extract:
# move updates into source tree
	cd ${WRKSRC}; \
	${MV} ../*pcx*.? ppm; \
	${MV} ../*rle*.? ../pnmtopng-2.37.3/*png*.? pnm;
	${CHMOD} -R o+r ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
