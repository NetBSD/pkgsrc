# $NetBSD: Makefile,v 1.6 2001/11/28 05:20:43 jlam Exp $

DISTNAME=	txt2html-1.28
CATEGORIES=	converters www
MASTER_SITES=	http://www.aigeek.com/txt2html/

MAINTAINER=	wennmach@netbsd.org
HOMEPAGE=	http://www.aigeek.com/txt2html/
COMMENT=	Text to HTML converter

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES
REPLACE_PERL=		txt2html.pl

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

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
