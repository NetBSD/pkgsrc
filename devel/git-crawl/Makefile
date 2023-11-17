# $NetBSD: Makefile,v 1.1 2023/11/17 21:20:50 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		git-crawl-0.0.20161010
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=magnusstahre/}
GITHUB_PROJECT=		git-stuff
GITHUB_TAG=		efb9c5106c218d7fabf98c45788670c15b5f1386

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/magnusstahre/git-stuff/
COMMENT=		Crawl through git commits

USE_LANGUAGES=		# none

REPLACE_SH=		git-crawl

NO_BUILD=		yes

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} git-crawl ${DESTDIR}${PREFIX}/bin/; \
	${INSTALL_DATA} README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
