# $NetBSD: Makefile,v 1.2 2001/10/18 11:39:23 wiz Exp $
#

DISTNAME=	gdchart0.10.1dev
PKGNAME=	gdchart-0.10.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fred.net/brv/chart/
COMMENT=	Easy to use, fast C API for creating charts and graphs

MAKEFILE=	makefile

USE_BUILDLINK_ONLY=	YES

post-patch:
	for fn in ${WRKSRC}/*.[ch]; do					      \
		${SED} 's/^#ifdef HAVE_JPEG/#ifndef NO_JPEG/' $${fn}	      \
			> $${fn}.new;					      \
		${MV} $${fn}.new $${fn};				      \
	done

do-install:
	${INSTALL_DATA}	${WRKSRC}/libgdchart.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/gdchart.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdc.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdcpie.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gifencode.h ${PREFIX}/include

post-install:
	${INSTALL_DATA_DIR} -d -m 0755 ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA_DIR} -d -m 0755 ${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp1.c ${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp2.c ${PREFIX}/share/examples/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_pie_samp.c \
		${PREFIX}/share/examples/gdchart

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
