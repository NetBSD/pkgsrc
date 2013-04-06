# $NetBSD: Makefile,v 1.8 2013/04/06 12:04:01 rodent Exp $
#

DISTNAME=		antixls-0.2b
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		http://www.af0.net/~dan/
EXTRACT_SUFX=		.perl

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.af0.net/~dan/?antixls
COMMENT=		Print XLS file with minimal formatting, or as CSV

DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} $$extract_file antixls
REPLACE_PERL+=	antixls
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/antixls ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
