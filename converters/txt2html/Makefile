# $NetBSD: Makefile,v 1.1.1.1 2000/10/20 14:53:08 wennmach Exp $

DISTNAME=	txt2html-1.28
CATEGORIES=	converters www
MASTER_SITES=	http://www.aigeek.com/txt2html/

MAINTAINER=	wennmach@netbsd.org
HOMEPAGE=	http://www.aigeek.com/txt2html/index.html

NO_BUILD=	# defined
USE_PERL5=	# defined

do-configure:
	${SED} -e "s:@PREFIX@:${PREFIX}:g" \
	    ${WRKSRC}/txt2html.pl > ${WRKSRC}/txt2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2html ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/txt2html.dict ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/sample.foot ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/sample.html ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/sample.txt ${PREFIX}/share/txt2html

.include "../../mk/bsd.pkg.mk"
