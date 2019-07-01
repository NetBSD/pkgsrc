# $NetBSD: Makefile,v 1.26 2019/07/01 04:08:43 ryoon Exp $

DISTNAME=	wmget-0.6.0-src
PKGNAME=	${DISTNAME:S/-src//}
WRKSRC=		${WRKDIR}/wmget
PKGREVISION=	17
CATEGORIES=	net
MASTER_SITES=	http://amtrickey.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://amtrickey.net/wmget/index.html
COMMENT=	Background download manager in a Window Maker dock app

SUBST_CLASSES+=		ldflags
SUBST_MESSAGE.ldflags=	Fixing hardcoded LDFLAGS.
SUBST_STAGE.ldflags=	pre-configure
SUBST_FILES.ldflags=	Makefile
SUBST_SED.ldflags=	-e 's|^LDFLAGS=|&${LDFLAGS}|'

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's|^PREFIX=.*|PREFIX=${LOCALBASE}|'

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmget ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmget.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
