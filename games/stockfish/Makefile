# $NetBSD: Makefile,v 1.4 2022/11/21 18:20:42 jperkin Exp $

DISTNAME=	stockfish-9-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	https://stockfish.s3.amazonaws.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stockfishchess.org/
COMMENT=	Strong open source chess engine
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/src
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/stockfish

BUILDLINK_TRANSFORM.NetBSD+=	rm:-flto rm:-m32
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/Readme.md ${DESTDIR}${PREFIX}/share/doc/stockfish

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
