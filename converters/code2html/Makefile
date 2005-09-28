# $NetBSD: Makefile,v 1.7 2005/09/28 20:52:18 rillig Exp $
#

DISTNAME=	code2html-0.9.1
CATEGORIES=	converters devel textproc
MASTER_SITES=	http://www.palfrader.org/code2html/all/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.palfrader.org/code2html/
COMMENT=	Convert a program source code to syntax highlighted HTML

NO_BUILD=	yes
REPLACE_PERL=	code2html
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/code2html.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
