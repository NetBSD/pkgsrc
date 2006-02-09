# $NetBSD: Makefile,v 1.25 2006/02/09 18:17:52 rillig Exp $

DISTNAME=	arc521e.pl8
PKGNAME=	arc-5.21e
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Create & extract files from DOS .ARC files

RESTRICTED=	Do not modify. Do not charge for redistribution.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/arc ${PREFIX:Q}/bin/
	${INSTALL_PROGRAM} ${WRKSRC:Q}/marc ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/arc.1 ${PREFIX:Q}/man/man1/

.include "../../mk/bsd.pkg.mk"
