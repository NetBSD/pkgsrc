# $NetBSD: Makefile,v 1.29 2006/05/03 05:55:28 wiz Exp $

DISTNAME=	arc-5.21o
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arc.sourceforge.net/
COMMENT=	Create & extract files from DOS .ARC files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/arc ${PREFIX:Q}/bin/
	${INSTALL_PROGRAM} ${WRKSRC:Q}/marc ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/arc.1 ${PREFIX:Q}/man/man1/

.include "../../mk/bsd.pkg.mk"
