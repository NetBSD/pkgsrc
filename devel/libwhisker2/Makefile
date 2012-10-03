# $NetBSD: Makefile,v 1.7 2012/10/03 21:54:32 wiz Exp $

DISTNAME=	libwhisker2-2.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.wiretrip.net/rfp/libwhisker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wiretrip.net/rfp/lw.asp
COMMENT=	Perl module geared specifically for HTTP testing

DEPENDS+=	p5-Net-SSLeay>=1.20:../../security/p5-Net-SSLeay

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
REPLACE_PERL=	scripts/api_demo.pl scripts/crawl_demo.pl \
		scripts/simple_demo.pl scripts/form_demo1.pl \
		scripts/form_demo2.pl scripts/prox.pl

do-build:
	@cd ${WRKSRC} && ${PERL5} Makefile.pl lib

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/libwhisker2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libdata/libwhisker2

	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${DESTDIR}${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${DESTDIR}${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/libwhisker2
	${INSTALL_DATA} ${WRKSRC}/LW2.pm ${DESTDIR}${PREFIX}/libdata/libwhisker2

.	for f in ${REPLACE_PERL}
		${INSTALL_SCRIPT} ${WRKSRC}/${f} \
			${DESTDIR}${PREFIX}/share/examples/libwhisker2
.	endfor

.include "../../mk/bsd.pkg.mk"
