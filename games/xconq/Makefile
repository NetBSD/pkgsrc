# $NetBSD: Makefile,v 1.49 2018/11/14 18:22:54 kleink Exp $

DISTNAME=		xconq-7.4.1
PKGREVISION=		14
CATEGORIES=		games x11
MASTER_SITES=		ftp://sources.redhat.com/pub/xconq/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sources.redhat.com/xconq/
COMMENT=		Xconq is a general strategy game system

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-alternate-scoresdir=${SCOREDIR}
CONFIGURE_ARGS+=	--with-tclconfig="${BUILDLINK_PREFIX.tcl}/lib"
CONFIGURE_ARGS+=	--with-tkconfig="${BUILDLINK_PREFIX.tk}/lib"

MAKE_ENV+=		LOCALBASE=${LOCALBASE}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}		\
			infodir=${PREFIX}/${PKGINFODIR}
INFO_FILES=	yes

# XXX SETGIDGAME should go away and the rest of these should come from
# the infrastructure.
SETGIDGAME=		yes
GAMEDIRMODE?=		775
GAMEDIR_PERMS?=		${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

SPECIAL_PERMS+=		bin/xconq ${SETGID_GAMES_PERMS}
SCOREDIR=		${VARBASE}/games/xconq/scores
REQD_DIRS_PERMS+=	${SCOREDIR} ${GAMEDIR_PERMS}

BUILD_DEFS+=	VARBASE SCOREDIR

post-build:
	cd ${WRKSRC}/doc && ${BUILD_MAKE_CMD} info

post-install:
	cd ${WRKSRC}/doc && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} 	\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install-info

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
