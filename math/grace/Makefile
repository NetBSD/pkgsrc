# $NetBSD: Makefile,v 1.19 2002/07/19 12:43:51 wiz Exp $
#

DISTNAME=	grace-5.1.4
PKGREVISION=	1
CATEGORIES=	math graphics x11
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/grace/src/ \
		ftp://ftp.ntua.gr/pub/graphics/grace/src/ \
		ftp://ftp.ru.xemacs.org/pub/math/grace/src/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/ \
		ftp://ftp2.netmor.com/pub/mirrors/grace/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Grace/
COMMENT=	GRaphing, Advanced Computation and Exploration of data

#DEPENDS+=	fftw-[0-9]*:../../math/fftw

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_FORTRAN=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-grace-home=${PREFIX}/grace
CONFIGURE_ARGS+=	--with-extra-incpath=${BUILDLINK_DIR}/include
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-install:
	${RM} -f ${PREFIX}/bin/xmgrace
	${LN} -s ${PREFIX}/grace/bin/xmgrace ${PREFIX}/bin

.include "../../devel/netcdf/buildlink.mk"
.include "../../fonts/t1lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../print/pdflib/buildlink.mk"
.include "../../x11/Xbae/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
