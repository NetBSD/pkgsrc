# $NetBSD: Makefile,v 1.8 2003/07/17 21:27:38 grant Exp $

DISTNAME=	txt2html-1.28
CATEGORIES=	converters www
MASTER_SITES=	http://www.aigeek.com/txt2html/

MAINTAINER=	wennmach@NetBSD.org
HOMEPAGE=	http://www.aigeek.com/txt2html/
COMMENT=	Text to HTML converter

USE_BUILDLINK2=	YES
NO_BUILD=	YES
REPLACE_PERL=	txt2html.pl

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

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
