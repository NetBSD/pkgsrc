# $NetBSD: Makefile,v 1.60 2018/11/12 03:52:06 ryoon Exp $

DISTNAME=	puzzles
PKGNAME=	puzzles-20160429
PKGREVISION=	5
CATEGORIES=	games
# distfile changes every day
MASTER_SITES=	# https://www.chiark.greenend.org.uk/~sgtatham/puzzles/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/puzzles/
COMMENT=	Collection of small one-player puzzle games by Simon Tatham
LICENSE=	mit

INSTALLATION_DIRS=	bin share/doc/puzzles

WRKSRC=		${WRKDIR}/puzzles-20160429.b31155b
USE_TOOLS+=	gmake pkg-config

BUILDLINK_TRANSFORM+=	rm:-Werror
MAKE_FLAGS=		prefix=${PREFIX}
MAKE_FLAGS=		gamesdir=${PREFIX}/bin
MAKE_FILE=		Makefile.gtk
CFLAGS+=		-DREVISION=${DISTNAME:S/puzzles-r//}

SUBST_CLASSES+=		ldflags
SUBST_SED.ldflags+=	-e 's/$$(CC)/$$(CC) $$(LDFLAGS)/g'
SUBST_FILES.ldflags+=	Makefile.gtk
SUBST_MESSAGE.ldflags=	Honoring LDFLAGS.
SUBST_STAGE.ldflags=	pre-build

post-install:
	${INSTALL_DATA} ${WRKSRC}/puzzles.txt \
		${DESTDIR}${PREFIX}/share/doc/puzzles

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
