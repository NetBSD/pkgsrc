# $NetBSD: Makefile,v 1.12 2012/10/03 00:20:10 asau Exp $
#

DISTNAME=	code2html-0.9.1
CATEGORIES=	converters devel textproc
MASTER_SITES=	http://www.palfrader.org/code2html/all/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.palfrader.org/code2html/
COMMENT=	Convert a program source code to syntax highlighted HTML

NO_BUILD=	yes
REPLACE_PERL=	code2html
USE_TOOLS+=	perl:run

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/code2html.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
