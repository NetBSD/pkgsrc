# $NetBSD: Makefile,v 1.29 2004/01/24 13:58:23 grant Exp $
#

DISTNAME=	grace-5.1.12
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

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_FORTRAN=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-grace-home=${PREFIX}/grace
CONFIGURE_ARGS+=	--without-bundled-xbae

post-install:
	${RM} -f ${PREFIX}/bin/xmgrace
	${LN} -s ${PREFIX}/grace/bin/xmgrace ${PREFIX}/bin

.include "../../devel/netcdf/buildlink2.mk"
.include "../../fonts/t1lib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../math/fftw2/buildlink2.mk"
.include "../../print/pdflib/buildlink2.mk"
.include "../../x11/Xbae/buildlink2.mk"
.include "../../x11/XmHTML/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
