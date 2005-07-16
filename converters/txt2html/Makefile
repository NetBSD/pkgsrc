# $NetBSD: Makefile,v 1.12 2005/07/16 19:10:38 jlam Exp $

DISTNAME=	txt2html-1.28
CATEGORIES=	converters www
MASTER_SITES=	http://www.aigeek.com/txt2html/

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://www.aigeek.com/txt2html/
COMMENT=	Text to HTML converter

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	txt2html.pl

INSTALLATION_DIRS=	bin

do-configure:
	${SED} -e "s:@PREFIX@:${PREFIX}:g" \
		${WRKSRC}/txt2html.pl > ${WRKSRC}/txt2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/txt2html ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/txt2html.dict ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/sample.foot ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/sample.html ${PREFIX}/share/txt2html
	${INSTALL_DATA} ${WRKSRC}/sample.txt ${PREFIX}/share/txt2html

.include "../../mk/bsd.pkg.mk"
