# $NetBSD: Makefile,v 1.1 2020/03/16 12:59:02 fcambus Exp $

DISTNAME=	nudoku-2.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jubalh/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://jubalh.github.io/nudoku/
COMMENT=	Ncurses based sudoku game
LICENSE=	gnu-gpl-v3

# Fix gettext includes
SUBST_CLASSES+=		includes
SUBST_STAGE.includes=	post-configure
SUBST_MESSAGE.includes=	Fix gettext includes
SUBST_FILES.includes=	src/main.c
SUBST_FILES.includes+=	src/sudoku.c
SUBST_SED.includes+=	-e 's,"gettext.h",<libintl.h>,'

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

FAKE_NCURSES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
