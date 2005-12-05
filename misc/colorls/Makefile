# $NetBSD: Makefile,v 1.20 2005/12/05 20:50:38 rillig Exp $

DISTNAME=		ls
PKGNAME=		colorls-2.2
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Ls that can use color to display file attributes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} \
			MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}
INSTALLATION_DIRS=	bin man/man1 man/cat1

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
