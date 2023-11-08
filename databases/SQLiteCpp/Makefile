# $NetBSD: Makefile,v 1.14 2023/11/08 13:18:22 wiz Exp $

DISTNAME=	SQLiteCpp-2.2.0
PKGREVISION=	12
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=SRombauts/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://srombauts.github.io/SQLiteCpp/
COMMENT=	C++ SQLite3 wrapper
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

.include "../../databases/sqlite3/buildlink3.mk"

post-install:
.for f in CHANGELOG.txt LICENSE.txt README.md TODO.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor

.include "../../mk/bsd.pkg.mk"
