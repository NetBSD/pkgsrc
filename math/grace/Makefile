# $NetBSD: Makefile,v 1.1.1.1 2000/02/03 19:47:40 drochner Exp $
#

DISTNAME=	grace-5.0.5
CATEGORIES=	math graphics x11
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Grace/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	netcdf:../../devel/netcdf
DEPENDS+=	jpeg-*:../../graphics/jpeg
DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	pdflib-*:../../print/pdflib
DEPENDS+=	t1lib-*:../../textproc/t1lib
DEPENDS+=	Xbae-*:../../x11/Xbae

USE_GMAKE=	yes
USE_FORTRAN=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-grace-home=${PREFIX}/grace \
		--enable-extra-incpath=${LOCALBASE}/include

ALL_TARGET=
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-install:
	${RM} -f ${PREFIX}/bin/xmgrace
	${LN} -s ${PREFIX}/grace/bin/xmgrace ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
