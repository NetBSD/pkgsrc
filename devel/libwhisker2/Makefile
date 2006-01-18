# $NetBSD: Makefile,v 1.1.1.1 2006/01/18 22:53:18 adrianp Exp $

DISTNAME=	libwhisker2-2.3
CATEGORIES=	devel
MASTER_SITES=	http://www.wiretrip.net/rfp/libwhisker/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.wiretrip.net/rfp/lw.asp
COMMENT=	Perl module geared specifically for HTTP testing

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

USE_TOOLS+=	perl
REPLACE_PERL=	scripts/api_demo.pl scripts/crawl_demo.pl \
		scripts/simple_demo.pl scripts/form_demo1.pl \
		scripts/form_demo2.pl scripts/prox.pl

do-build:
	@cd ${WRKSRC} && ${PERL5} Makefile.pl lib

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/libwhisker2
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/libwhisker2

	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/LW2.pm ${PREFIX}/libdata/libwhisker2

.	for f in ${REPLACE_PERL}
		${INSTALL_SCRIPT} ${WRKSRC}/${f} \
			${PREFIX}/share/examples/libwhisker2
.	endfor

.include "../../mk/bsd.pkg.mk"
