# $NetBSD: Makefile,v 1.32 2004/10/03 00:12:56 tv Exp $
#

DISTNAME=	grace-5.1.14
PKGREVISION=	1
CATEGORIES=	math graphics x11
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/ \
		ftp://linux.mathematik.tu-darmstadt.de/pub/linux/mirrors/misc/grace/src/ \
		ftp://ftp.fu-berlin.de/unix/graphics/grace/src/ \
		ftp://ftp.ntua.gr/pub/graphics/grace/src/ \
		ftp://ftp.ru.xemacs.org/pub/math/grace/src/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/ \
		ftp://ftp2.netmor.com/pub/mirrors/grace/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Grace/
COMMENT=	GRaphing, Advanced Computation and Exploration of data

USE_BUILDLINK3=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_FORTRAN=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-grace-home=${PREFIX}/grace
CONFIGURE_ARGS+=	--without-bundled-xbae

post-install:
	${RM} -f ${PREFIX}/bin/xmgrace
	${LN} -s ${PREFIX}/grace/bin/xmgrace ${PREFIX}/bin

.include "../../devel/netcdf/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../x11/Xbae/buildlink3.mk"
.include "../../x11/XmHTML/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
