# $NetBSD: Makefile,v 1.1 2021/01/30 14:30:47 ryoon Exp $

PKGNAME=	ja-stick-ttf-20201216
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Stick/b77e3fdfc09adb034c79b59fb5ed3acefba9a009/fonts/ttf/
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
