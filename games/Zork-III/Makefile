# $NetBSD: Makefile,v 1.1 2026/06/29 15:27:44 jnemeth Exp $

DISTNAME=	zork3
PKGNAME=	Zork-III-1.0	# fake version number as this will never change
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=historicalsource/zork3/raw/refs/heads/master/COMPILED/}
EXTRACT_SUFX=	.z3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opensource.microsoft.com/blog/2025/11/20/preserving-code-that-shaped-generations-zork-i-ii-and-iii-go-open-source
COMMENT=	ZORK I: The Dungeon Master
LICENSE=	mit

WRKSRC=		${WRKDIR}
INSTALLATION_DIRS+=	games/zcode

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/zork3.z3 ${DESTDIR}${PREFIX}/games/zcode

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
