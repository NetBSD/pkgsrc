# $NetBSD: Makefile,v 1.3 2003/07/21 16:36:12 martti Exp $
#

DISTNAME=	code2html-0.9.1
CATEGORIES=	converters devel textproc
MASTER_SITES=	http://www.palfrader.org/code2html/all/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.palfrader.org/code2html/
COMMENT=	Convert a program source code to syntax highlighted HTML

NO_BUILD=	# defined
REPLACE_PERL=	${WRKSRC}/code2html
USE_PERL5=	run

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/code2html.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
