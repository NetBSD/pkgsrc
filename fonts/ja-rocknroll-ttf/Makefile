# $NetBSD: Makefile,v 1.2 2024/08/16 15:26:29 ryoon Exp $

PKGNAME=	ja-rocknroll-ttf-20210904
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/RocknRoll/29a2aa8bb7ab10702dee769ee681a9baeeb52ec1/fonts/ttf/
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
