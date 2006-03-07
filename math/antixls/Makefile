# $NetBSD: Makefile,v 1.1.1.1 2006/03/07 15:19:59 dillo Exp $
#

DISTNAME=		antixls-0.2b
CATEGORIES=		math
MASTER_SITES=		http://www.af0.net/~dan/
EXTRACT_SUFX=		.perl

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.af0.net/~dan/?antixls
COMMENT=		Print XLS file with minimal formatting, or as CSV

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} antixls
REPLACE_PERL+=	antixls
NO_BUILD=	YES

DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/antixls ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
