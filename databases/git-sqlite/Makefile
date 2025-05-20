# $NetBSD: Makefile,v 1.1 2025/05/20 16:48:21 schmonz Exp $

DISTNAME=		git-sqlite-0.1
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=cannadayr/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/cannadayr/git-sqlite/
COMMENT=		Git diff and merge driver for SQLite
LICENSE=		mit

DEPENDS+=		git-base-[0-9]*:../../devel/git-base
DEPENDS+=		sqlite3-[0-9]*:../../databases/sqlite3
DEPENDS+=		sqlite3-diff-[0-9]*:../../databases/sqlite3-diff

USE_LANGUAGES=		# none
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoreconf autoconf automake bash:run

REPLACE_BASH=		src/util.sh src/*.in

INSTALLATION_DIRS=	share/doc/${PKGBASE}

pre-configure:
	cd ${WRKSRC} && ${CONFIG_SHELL} ./reconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
