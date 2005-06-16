# $NetBSD: Makefile,v 1.28 2005/06/16 06:57:55 jlam Exp $
#

DISTNAME=		nighthawk-2.1
PKGREVISION=		1
CATEGORIES=		x11 games
MASTER_SITES=		${MASTER_SITE_BACKUP}
EXTRACT_SUFX=		.tgz

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		nighthawk-2.1a.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://jsno.arafuraconnect.com.au/proj_linux/nighthawk.html
COMMENT=		C64 Paradroid clone

WRKSRC=			${WRKDIR}/nighthawk
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

MAKE_ENV+=		OSTYPE=${OPSYS}
CPPFLAGS+=		-DPREFIX="\"${PREFIX}\"" \
			-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\"" \
			-DVARBASE="\"${VARBASE}\""

INSTALLATION_DIRS=	bin

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

post-build:
	cd ${WRKSRC}/src_sound && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} nighthawk_sound

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk/data
	cd ${WRKSRC}/data && ${PAX} -rw . ${PREFIX}/share/nighthawk/data
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/nighthawk
	${FIND} ${PREFIX}/share/nighthawk -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${PREFIX}/share/nighthawk -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${INSTALL_PROGRAM} ${WRKSRC}/src/nighthawk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src_sound/nighthawk_sound ${PREFIX}/bin
	${CHGRP} ${GAMEGRP} ${PREFIX}/bin/nighthawk
	${CHMOD} g+s ${PREFIX}/bin/nighthawk
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/nighthawk/README
	${INSTALL} -o ${ROOT_USER} -g ${GAMEGRP} -m 664 /dev/null ${VARBASE}/games/nighthawk.scores

.include "../../mk/bsd.pkg.mk"
