# $NetBSD: Makefile,v 1.26 2012/10/08 09:57:18 asau Exp $

DISTNAME=		ls
PKGNAME=		colorls-2.2
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ls(1) that can use color to display file attributes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_FEATURES+=		fts_open

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} \
			MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

CFLAGS.SunOS+=		-Du_quad_t=uint64_t -DS_ISTXT=S_ISVTX

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
