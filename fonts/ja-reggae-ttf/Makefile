# $NetBSD: Makefile,v 1.1 2021/01/30 14:27:23 ryoon Exp $

PKGNAME=	ja-reggae-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Reggae/3c27761ba6d5329ca5aaadced961501dfbdf32b3/fonts/ttf/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	ReggaeOne-Regular.ttf

MAINTAINER=	ryoon@NetBSD.org
COMMENT=	Reggae Japanese boys' magazine-style font from Fontworks
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
