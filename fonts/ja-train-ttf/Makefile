# $NetBSD: Makefile,v 1.2 2024/08/16 15:28:28 ryoon Exp $

PKGNAME=	ja-train-ttf-20210624
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Train/2972a9857a8332c2af86b221799558c177ba9012/fonts/ttf/
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
