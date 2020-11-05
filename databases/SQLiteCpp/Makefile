# $NetBSD: Makefile,v 1.8 2020/11/05 09:06:44 ryoon Exp $

DISTNAME=	SQLiteCpp-2.2.0
PKGREVISION=	6
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
