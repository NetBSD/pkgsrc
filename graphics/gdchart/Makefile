# $NetBSD: Makefile,v 1.1 2001/10/18 11:13:56 darcy Exp $
# FreeBSD Id: ports/graphics/gdchart/Makefile,v 1.5 2001/10/07 02:03:41 petef Exp

DISTNAME=	gdchart0.10.1dev
PKGNAME=	gdchart-0.10.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fred.net/brv/chart/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fred.net/brv/chart/
COMMENT=	Easy to use, fast C API for creating charts and graphs

DEPENDS=	gd-1.8*:../../graphics/gd

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${DISTNAME}

post-patch:
	${PERL5} -i -pe 's/^#ifdef HAVE_JPEG/#ifndef NO_JPEG/' ${WRKSRC}/*.[ch]

do-install:
	${INSTALL_DATA}	${WRKSRC}/libgdchart.a ${PREFIX}/lib
	${INSTALL_DATA}	${WRKSRC}/gdchart.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdc.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gdcpie.h ${PREFIX}/include
	${INSTALL_DATA}	${WRKSRC}/gifencode.h ${PREFIX}/include

post-install:
	@${INSTALL} -d -m 0755 ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp1.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_samp2.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/gdc_pie_samp.c ${PREFIX}/share/doc/gdchart
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gdchart
	@${ECHO} "================================================================================"
	@${ECHO} "Have a look at the sample code and README in ${PREFIX}/share/doc/${PORTNAME}."
	@${ECHO} "To compile gdc_samp1, try something like:"
	@${ECHO}
	@${ECHO} "gcc -I${PREFIX}/include -o gdc_samp1 gdc_samp1.c -L${PREFIX}/lib -lgdchart -lgd"
	@${ECHO} "================================================================================"

.include "../../mk/bsd.pkg.mk"
