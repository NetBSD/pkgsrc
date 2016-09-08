# $NetBSD: Makefile,v 1.31 2016/09/08 14:41:36 jperkin Exp $

DISTNAME=	ls
PKGNAME=	colorls-2.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Uses color with ls(1) to display file attributes

USE_FEATURES+=		fts_open
USE_TOOLS=		nroff

RESTRICTED=		Already in MASTER_SITE_LOCAL
NO_SRC_ON_FTP=		${RESTRICTED}

MANCOMPRESSED_IF_MANZ=	yes
MAKE_ENV+=		BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} \
			MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}
MAKE_ENV+=		LDADD=${LIBS:Q}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

CFLAGS.SunOS+=		-Du_quad_t=uint64_t -DS_ISTXT=S_ISVTX

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
