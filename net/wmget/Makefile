# $NetBSD: Makefile,v 1.42 2023/12/24 14:40:35 zafer Exp $

DISTNAME=	wmget-0.6.0-src
PKGNAME=	${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/wmget
PKGREVISION=	32
CATEGORIES=	net
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://amtrickey.net/wmget/index.html
COMMENT=	Background download manager in a Window Maker dock app
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmget ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmget.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
