# $NetBSD: Makefile,v 1.10 2024/05/07 16:01:06 nia Exp $

DISTNAME=	nudoku-4.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jubalh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jubalh.github.io/nudoku/
COMMENT=	Ncurses based sudoku game
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

# Fix gettext includes
SUBST_CLASSES+=		includes
SUBST_STAGE.includes=	post-configure
SUBST_MESSAGE.includes=	Fix gettext includes
SUBST_FILES.includes+=	src/sudoku.c
SUBST_SED.includes+=	-e 's,"gettext.h",<libintl.h>,'

USE_TOOLS+=		autoreconf automake autoconf autopoint gettext
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_CURSES=		wide
FAKE_NCURSES=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ENV+=		ncursesw_CFLAGS=-I${BUILDLINK_PREFIX.curses}/include
CONFIGURE_ENV+=		ncursesw_LIBS=${BUILDLINK_LDADD.curses:Q}

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
