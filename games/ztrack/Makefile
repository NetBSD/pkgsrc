# $NetBSD: Makefile,v 1.3 2020/05/16 13:01:15 rillig Exp $

DISTNAME=	ztrack-1.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/arcade/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# Nothing better available
HOMEPAGE=	${MASTER_SITE_SUNSITE:=games/arcade/}
COMMENT=	Simple curses-based pseudo-3D driving game
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${PKGBASE}

MAKE_FLAGS+=	BINDIR=${PREFIX}/bin
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man6

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Link with the proper curses type
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e '/LIBS/ s,-lncurses,-l${BUILDLINK_LIBNAME.curses},'
SUBST_NOOP_OK.makefile=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
