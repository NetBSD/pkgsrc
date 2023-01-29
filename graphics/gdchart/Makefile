# $NetBSD: Makefile,v 1.45 2023/01/29 21:14:39 ryoon Exp $

DISTNAME=	gdchart0.11.5dev
PKGNAME=	gdchart-0.11.5
PKGREVISION=	22
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.fred.net/brv/chart/
COMMENT=	Easy to use, fast C API for creating charts and graphs

USE_LIBTOOL=		yes
INSTALLATION_DIRS=	include lib

#TEST_TARGET=	gdc_samp1 gdc_samp2 gdc_pie_samp ft_samp

post-patch:
	for fn in ${WRKSRC}/*.[ch]; do					\
		${SED} 's/^#ifdef HAVE_JPEG/#ifndef NO_JPEG/' $${fn}	\
			> $${fn}.new;					\
		${MV} $${fn}.new $${fn};				\
	done

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libgdchart.la \
		 ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/gdchart.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdc.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdcpie.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA_DIR} -d -m 0755 ${DESTDIR}${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/gdchart
	${INSTALL_DATA_DIR} -d -m 0755 \
		${DESTDIR}${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp1.c \
		${DESTDIR}${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp2.c \
		${DESTDIR}${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_pie_samp.c \
		${DESTDIR}${PREFIX}/share/examples/gdchart

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
