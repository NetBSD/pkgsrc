# $NetBSD: Makefile,v 1.3 2000/08/23 23:14:30 tron Exp $
#

DISTNAME=	grace-5.1.0
CATEGORIES=	math graphics x11
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Grace/

DEPENDS+=	netcdf:../../devel/netcdf
DEPENDS+=	jpeg-6*:../../graphics/jpeg
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	png>=0.9.6:../../graphics/png
DEPENDS+=	pdflib>=3.0:../../print/pdflib
DEPENDS+=	t1lib-1.0.1:../../textproc/t1lib
DEPENDS+=	Xbae-*:../../x11/Xbae
#DEPENDS+=	fftw-*:../../math/fftw

USE_GMAKE=	YES
USE_FORTRAN=	YES
USE_MOTIF=	YES
USE_XPM=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-grace-home=${PREFIX}/grace \
		--with-extra-incpath=${LOCALBASE}/include:${X11BASE}/include

ALL_TARGET=
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-install:
	${RM} -f ${PREFIX}/bin/xmgrace
	${LN} -s ${PREFIX}/grace/bin/xmgrace ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
