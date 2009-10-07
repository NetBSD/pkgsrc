# $NetBSD: Makefile,v 1.33 2009/10/07 15:38:03 joerg Exp $

DISTNAME=		xgalaga-2.0.34
PKGREVISION=		4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Very fast true-to-the-original port of galaga for X11

NO_SRC_ON_FTP=		"already in MASTER_SITE_LOCAL"

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/xgalaga
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
SETGIDGAME=		yes
MAKE_ENV+=		GAMEOWN=${GAMEOWN:Q} GAMEGRP=${GAMEGRP:Q} \
			GAMEMODE=${GAMEMODE:Q} GAMEDATAMODE=${GAMEDATAMODE:Q}

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

INSTALLATION_DIRS=	libexec

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/xgalaga/README

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
