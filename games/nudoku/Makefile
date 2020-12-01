# $NetBSD: Makefile,v 1.4 2020/12/01 11:09:18 nia Exp $

DISTNAME=	nudoku-2.1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jubalh/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://jubalh.github.io/nudoku/
COMMENT=	Ncurses based sudoku game
LICENSE=	gnu-gpl-v3

# Fix gettext includes
SUBST_CLASSES+=		includes
SUBST_STAGE.includes=	post-configure
SUBST_MESSAGE.includes=	Fix gettext includes
SUBST_FILES.includes+=	src/sudoku.c
SUBST_SED.includes+=	-e 's,"gettext.h",<libintl.h>,'

USE_TOOLS+=		autoreconf automake autoconf autopoint gettext
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

FAKE_NCURSES=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
