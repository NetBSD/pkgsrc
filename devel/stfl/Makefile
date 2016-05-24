# $NetBSD: Makefile,v 1.1 2016/05/24 09:20:07 leot Exp $

MAJOR=		0
MINOR=		24
DISTNAME=	stfl-${MAJOR}.${MINOR}
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clifford.at/stfl/
COMMENT=	Library which implements a curses-based widget set for text terminals
LICENSE=	gnu-lgpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_GNU_ICONV=	yes

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

# Makefile
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e "s|LDLIBS.*|& -liconv -Wl,-R${PREFIX}/lib|"

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-*-*)
SUBST_CLASSES+=		curses
SUBST_STAGE.curses=	pre-build
SUBST_MESSAGE.curses=	replacing ncursesw includes by native curses
SUBST_FILES.curses=	stfl.pc.in Makefile
SUBST_SED.curses=	-e "s|-lncursesw|-lcurses|g"
.include "../../mk/curses.buildlink3.mk"
.else
.include "../../devel/ncursesw/buildlink3.mk"
.endif

PLIST_SUBST+=	MAJOR=${MAJOR:Q} MINOR=${MINOR:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
