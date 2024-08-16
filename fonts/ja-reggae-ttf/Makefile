# $NetBSD: Makefile,v 1.2 2024/08/16 15:25:42 ryoon Exp $

PKGNAME=	ja-reggae-ttf-20210902
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Reggae/fe9be09d02ad8ba5e71d5ce24efc5249fe77dcfc/fonts/ttf/
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
