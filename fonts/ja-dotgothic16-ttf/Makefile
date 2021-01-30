# $NetBSD: Makefile,v 1.1 2021/01/30 14:22:25 ryoon Exp $

PKGNAME=	ja-dotgothic16-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/DotGothic16/65e34c7002c9a74b4be6201bb3a059a5f00580b9/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	DotGothic16-Regular.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Dotgothic old 16x16 gothic bitmap-style font from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
