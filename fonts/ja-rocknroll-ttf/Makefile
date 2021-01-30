# $NetBSD: Makefile,v 1.1 2021/01/30 14:29:00 ryoon Exp $

PKGNAME=	ja-rocknroll-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/RocknRoll/99f160432a3dd5c9234519bd439555ba588b7362/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	RocknRollOne-Regular.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	RocknRoll pop-style font from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
