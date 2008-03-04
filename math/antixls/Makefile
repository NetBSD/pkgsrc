# $NetBSD: Makefile,v 1.4 2008/03/04 18:12:58 jlam Exp $
#

DISTNAME=		antixls-0.2b
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		http://www.af0.net/~dan/
EXTRACT_SUFX=		.perl

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.af0.net/~dan/?antixls
COMMENT=		Print XLS file with minimal formatting, or as CSV

DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} antixls
REPLACE_PERL+=	antixls
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/antixls ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
