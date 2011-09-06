# $NetBSD: Makefile,v 1.24 2011/09/06 20:39:50 wiz Exp $

DISTNAME=		ls
PKGNAME=		colorls-2.2
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ls(1) that can use color to display file attributes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} \
			MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
