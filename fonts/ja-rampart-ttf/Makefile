# $NetBSD: Makefile,v 1.2 2024/08/16 15:24:55 ryoon Exp $

PKGNAME=	ja-rampart-ttf-20210623
CATEGORIES=	fonts
MASTER_SITES=	https://raw.githubusercontent.com/fontworks-fonts/Rampart/ba27f91040709583f83e331680776fbea97d560d/fonts/ttf/
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
