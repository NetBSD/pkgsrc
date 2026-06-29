# $NetBSD: Makefile,v 1.1 2026/06/29 15:26:07 jnemeth Exp $

DISTNAME=	zork1
PKGNAME=	Zork-I-1.0	# fake version number as this will never change
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=historicalsource/zork1/raw/refs/heads/master/COMPILED/}
EXTRACT_SUFX=	.z3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opensource.microsoft.com/blog/2025/11/20/preserving-code-that-shaped-generations-zork-i-ii-and-iii-go-open-source
COMMENT=	ZORK I: The Great Underground Empire
LICENSE=	mit

WRKSRC=		${WRKDIR}
INSTALLATION_DIRS+=	games/zcode

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/zork1.z3 ${DESTDIR}${PREFIX}/games/zcode

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
