# $NetBSD: Makefile,v 1.15 2004/01/20 12:15:41 agc Exp $
#

DISTNAME=		nighthawk-2.1
CATEGORIES=		x11 games
MASTER_SITES=		http://jsno.downunder.net.au/proj_linux/nighthawk.html
EXTRACT_SUFX=		.tgz

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		nighthawk-2.1a.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://jsno.arafuraconnect.com.au/proj_linux/nighthawk.html
COMMENT=		C=64 Paradroid clone

WRKSRC=			${WRKDIR}/nighthawk
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES

post-build:
	cd ${WRKSRC}/src_sound && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} nighthawk_sound

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk/data
	cd ${WRKSRC}/data && ${PAX} -rw . ${PREFIX}/share/nighthawk/data
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/nighthawk
	${FIND} ${PREFIX}/share/nighthawk -type f -print | ${XARGS} ${CHMOD} 444
	${FIND} ${PREFIX}/share/nighthawk -type d -print | ${XARGS} ${CHMOD} 555
	${INSTALL_PROGRAM} ${WRKSRC}/src/nighthawk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src_sound/nighthawk_sound ${PREFIX}/bin
	${CHGRP} games ${PREFIX}/bin/nighthawk
	${CHMOD} g+s ${PREFIX}/bin/nighthawk
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/nighthawk/README
	${INSTALL} -o ${ROOT_USER} -g games -m 664 /dev/null /var/games/nighthawk.scores

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
