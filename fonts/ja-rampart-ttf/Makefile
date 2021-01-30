# $NetBSD: Makefile,v 1.1 2021/01/30 14:25:54 ryoon Exp $

PKGNAME=	ja-rampart-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Rampart/b3c1328e80810121b5080b7a4dd5ea419a02dafa/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	RampartOne-Regular.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Rampart outline shadow font from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
