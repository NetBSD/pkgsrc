# $NetBSD: Makefile,v 1.2 2024/08/16 15:27:16 ryoon Exp $

PKGNAME=	ja-stick-ttf-20210622
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Stick/069a1101e3fd51e60205710157f8b6a996ffea61/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	Stick-Regular.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Stick straight-line font from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
