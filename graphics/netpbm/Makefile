# $NetBSD: Makefile,v 1.30 1999/10/08 21:12:49 jlam Exp $
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
		pnmtopng-2.37.2.tar.gz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png

WRKSRC=		${WRKDIR}/netpbm
MAKE_ENV +=	PREFIX=${PREFIX} MANCP="${INSTALL_MAN}"
NO_CONFIGURE=	yes

post-extract:
# move updates into source tree
	cd ${WRKSRC}; \
	${MV} ../*pcx*.? ppm; \
	${MV} ../*rle*.? ../pnmtopng-2.37.2/*png*.? pnm;
	${CHMOD} -R o+r ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
