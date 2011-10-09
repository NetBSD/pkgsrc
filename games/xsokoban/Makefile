# $NetBSD: Makefile,v 1.3 2011/10/09 10:02:46 cheusov Exp $
#

DISTNAME=	xsokoban-3.3c
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cs.cornell.edu/andru/release/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.cs.cornell.edu/andru/release/
COMMENT=	Classic logical game

WRKSRC=		${WRKDIR}/xsokoban

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf

PKG_DESTDIR_SUPPORT=	user-destdir

SAVEPATH=		${VARBASE}/games/xsokoban
SCOREFILE=		${SAVEPATH}/scores

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/xsokoban
CONFIGURE_ENV+=		X11BASE=${X11BASE}

# For removing setting SETGIDGAME from here pkgsrc should be fixed
SETGIDGAME=		yes

SPECIAL_PERMS=		bin/xsokoban ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${SAVEPATH} ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}

BUILD_TARGET=		xsokoban

CPPFLAGS+=		-DROOTDIR="\"${PREFIX}/share/xsokoban\""
CPPFLAGS+=		-DSAVEPATH="\"${SAVEPATH}\""
CPPFLAGS+=		-DSCOREPATH="\"${SCOREFILE}\""

AUTO_MKDIRS=		yes

AUTOCONF_REQD=		2.59

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
