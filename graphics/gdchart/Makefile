# $NetBSD: Makefile,v 1.12 2004/04/25 04:40:48 snj Exp $
#

DISTNAME=	gdchart0.11.4dev
PKGNAME=	gdchart-0.11.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.fred.net/brv/chart/
COMMENT=	Easy to use, fast C API for creating charts and graphs

MAKEFILE=	makefile

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

TEST_TARGET=	gdc_samp1 gdc_samp2 gdc_pie_samp ft_samp

post-patch:
	for fn in ${WRKSRC}/*.[ch]; do					      \
		${SED} 's/^#ifdef HAVE_JPEG/#ifndef NO_JPEG/' $${fn}	      \
			> $${fn}.new;					      \
		${MV} $${fn}.new $${fn};				      \
	done

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/libgdchart.la \
		 ${PREFIX}/lib
	${LIBTOOL} -n --finish ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/gdchart.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdc.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdcpie.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gifencode.h ${PREFIX}/include
	${INSTALL_DATA_DIR} -d -m 0755 ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA_DIR} -d -m 0755 ${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp1.c ${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp2.c ${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_pie_samp.c \
		${PREFIX}/share/examples/gdchart

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
