# $NetBSD: Makefile,v 1.15 2005/02/28 02:26:59 ben Exp $

DISTNAME=		ularn
PKGNAME=		ularn-6.12.92
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://www.cordier.com/ularn/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.cordier.com/ularn/
COMMENT=		Fantasy roguelike game based on vintage larn

WRKSRC=			${WRKDIR}
HAS_CONFIGURE=          # defined
CONFIGURE_ENV+=         PREFIX=${LOCALBASE}
CONFIGURE_SCRIPT=       ./Configure
CONFIGURE_ARGS+=        -d

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		termlib
SUBST_MESSAGE.termlib=	"Adding -lcompat dependency."
SUBST_STAGE.termlib=	post-patch
SUBST_FILES.termlib=	Configure
SUBST_SED.termlib=	-e 's,^termlib=..termlib,& -lcompat,'
.endif

.if ${OPSYS} == "Linux"
CFLAGS+=		-I/usr/include/ncurses -DGETOPT
.endif

pre-configure:
	${MV} ${WRKSRC}/Configure ${WRKSRC}/Configure.template
	${SED} 's:XXXLIBDIRXXX:${LOCALBASE}/share/Ularn:;\
		s:XXXBINDIRXXX:${LOCALBASE}/bin:' \
		<${WRKSRC}/Configure.template \
		>${WRKSRC}/Configure
	${CHMOD} u+x ${WRKSRC}/Configure

post-install:
	${CHGRP} games ${LOCALBASE}/bin/Ularn
	${CHMOD} g+s ${LOCALBASE}/bin/Ularn
	${CHMOD} g+w ${LOCALBASE}/share/Ularn

.include "../../mk/bsd.pkg.mk"
