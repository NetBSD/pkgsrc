# $NetBSD: Makefile,v 1.14 2025/05/17 19:38:39 zafer Exp $
#

DISTNAME=		news-0.2
CATEGORIES=		sysutils
MASTER_SITES=		https://www.netmeister.org/apps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.netmeister.org/
COMMENT=		System V news(1)

USE_FEATURES=		utimes fts_open

MAKE_ENV+=		LIBS=${LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/news ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/news.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
