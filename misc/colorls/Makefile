# $NetBSD: Makefile,v 1.18 2005/03/24 21:12:57 wiz Exp $

DISTNAME=		ls
PKGNAME=		colorls-2.2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Ls that can use color to display file attributes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

MANCOMPRESSED_IF_MANZ=	yes

INSTALLATION_DIRS=	bin man/man1 man/cat1

pre-patch:
	${CP} ${WRKSRC}/ls.1 ${WRKSRC}/colorls.1

.include "../../mk/bsd.pkg.mk"
