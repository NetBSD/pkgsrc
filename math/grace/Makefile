# $NetBSD: Makefile,v 1.69 2018/08/16 18:54:59 adam Exp $

DISTNAME=	grace-5.1.25
PKGREVISION=	5
CATEGORIES=	math graphics x11
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/grace/src/stable/
MASTER_SITES+=	ftp://ftp.fu-berlin.de/unix/graphics/grace/src/stable/
MASTER_SITES+=	ftp://ftp.ru.xemacs.org/pub/math/grace/src/stable/
MASTER_SITES+=	ftp://ftp.u-aizu.ac.jp/pub/SciEng/math/grace/src/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plasma-gate.weizmann.ac.il/Grace/
COMMENT=	GRaphing, Advanced Computation and Exploration of data
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES=		c fortran77
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-grace-home=${PREFIX}/grace
CONFIGURE_ARGS+=	--without-bundled-xbae

INSTALLATION_DIRS=	bin

# test require X
#TEST_TARGET=		check

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/xmgrace
	${LN} -s ${DESTDIR}${PREFIX}/grace/bin/xmgrace ${DESTDIR}${PREFIX}/bin

.include "../../devel/netcdf/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../print/pdflib-lite/buildlink3.mk"
.include "../../x11/Xbae/buildlink3.mk"
.include "../../x11/XmHTML/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
