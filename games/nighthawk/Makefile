# $NetBSD: Makefile,v 1.40 2012/12/20 22:03:01 joerg Exp $
#

DISTNAME=		nighthawk-2.1
PKGREVISION=		5
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_BACKUP}
EXTRACT_SUFX=		.tgz

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		nighthawk-2.1a.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jsno.arafuraconnect.com.au/proj_linux/nighthawk.html
COMMENT=		C64 Paradroid clone

WRKSRC=			${WRKDIR}/nighthawk
USE_TOOLS+=		gmake pax
USE_LANGUAGES=		c c++

MAKE_ENV+=		OSTYPE=${OPSYS}
CPPFLAGS+=		-DPREFIX="\"${PREFIX}\"" \
			-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\"" \
			-DVARBASE="\"${VARBASE}\""

SETGIDGAME=		yes
CONF_FILES_PERMS=	/dev/null ${VARBASE}/games/nighthawk.scores	\
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/nighthawk ${SETGID_GAMES_PERMS}
BUILD_DEFS+=		VARBASE GAMEDATAMODE

AUTO_MKDIRS=		yes
MAKE_DIRS=		${VARBASE}/games

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

post-build:
	cd ${WRKSRC}/src_sound && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} nighthawk_sound

do-install:
	cd ${WRKSRC}/data && pax -rw . ${DESTDIR}${PREFIX}/share/nighthawk/data
	${FIND} ${DESTDIR}${PREFIX}/share/nighthawk -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/nighthawk -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${INSTALL_PROGRAM} ${WRKSRC}/src/nighthawk ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src_sound/nighthawk_sound ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/nighthawk/README

.include "../../mk/bsd.pkg.mk"
