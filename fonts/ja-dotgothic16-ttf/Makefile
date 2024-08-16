# $NetBSD: Makefile,v 1.2 2024/08/16 15:23:03 ryoon Exp $

PKGNAME=	ja-dotgothic16-ttf-20211022
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/DotGothic16/14517183ab2f75e8bccafc5a0bff6685d268c687/fonts/ttf/
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
