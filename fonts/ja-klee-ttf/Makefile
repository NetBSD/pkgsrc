# $NetBSD: Makefile,v 1.1 2021/01/30 14:24:13 ryoon Exp $

PKGNAME=	ja-klee-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Klee/2adf612552682fb9336902d0ee727fe22baf187a/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	KleeOne-Regular.ttf
DISTFILES+=	KleeOne-SemiBold.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Klee handwritten fonts from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
