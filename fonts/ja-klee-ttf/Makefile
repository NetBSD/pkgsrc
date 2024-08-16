# $NetBSD: Makefile,v 1.2 2024/08/16 15:24:00 ryoon Exp $

PKGNAME=	ja-klee-ttf-20210623
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Klee/8b0532731b63ad8a445ca341d8d7d941079b83ab/fonts/ttf/
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
