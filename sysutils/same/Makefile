# $NetBSD: Makefile,v 1.2 2006/08/04 22:46:27 rillig Exp $

DISTNAME=	same-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.bitwizard.nl/same/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.bitwizard.nl/
COMMENT=	Find identical files and link(2) them to save disk space

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_FLAGS+=		BINDIR=${PREFIX}/bin
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_FLAGS+=		MANOWN=${MANOWN} MANGRP=${MANGRP}

post-extract:
	cd ${FILESDIR} && cp -f Makefile same.1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
