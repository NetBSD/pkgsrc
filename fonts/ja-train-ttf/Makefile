# $NetBSD: Makefile,v 1.1 2021/01/30 14:32:23 ryoon Exp $

PKGNAME=	ja-train-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Train/1771787f91e5750f928d2abc6ad7c5f452d6298f/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	TrainOne-Regular.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Train gothic-style font from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
