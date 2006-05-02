# $NetBSD: Makefile,v 1.28 2006/05/02 19:06:45 wiz Exp $

DISTNAME=	arc-5.21o
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arc.sourceforge.net/
COMMENT=	Create & extract files from DOS .ARC files

# Is under GPL as of 2003, but the README still contains
# another clause -- in contact with author about it.
# wiz -- 20060502
LICENSE=	arc-license
RESTRICTED=	Do not modify. Do not charge for redistribution.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/arc ${PREFIX:Q}/bin/
	${INSTALL_PROGRAM} ${WRKSRC:Q}/marc ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/arc.1 ${PREFIX:Q}/man/man1/

.include "../../mk/bsd.pkg.mk"
