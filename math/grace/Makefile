# $NetBSD: Makefile,v 1.9 2001/05/22 09:32:24 wiz Exp $

DISTNAME=	grace-5.1.2
CATEGORIES=	math graphics x11
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Grace/
COMMENT=	GRaphing, Advanced Computation and Exploration of data

DEPENDS+=	netcdf>=3.4:../../devel/netcdf
DEPENDS+=	jpeg-6*:../../graphics/jpeg
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	pdflib>=3.0:../../print/pdflib
DEPENDS+=	t1lib>=1.0.1:../../textproc/t1lib
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
