# $NetBSD: Makefile,v 1.10 2001/12/05 15:00:45 agc Exp $
#

DISTNAME=		nighthawk-2.1
WRKSRC=			${WRKDIR}/nighthawk
CATEGORIES=		x11 games
MASTER_SITES=		http://jsno.downunder.net.au/proj_linux/nighthawk.html
EXTRACT_SUFX=		.tgz

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		nighthawk-2.1a.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.downunder.net.au/~jsno/
COMMENT=		C=64 Paradroid clone

USE_GMAKE=		YES
USE_X11=		YES
USE_XPM=		YES

post-build:
	cd ${WRKSRC}/src_sound ; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} nighthawk_sound

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk/data
	( cd ${WRKSRC}/data ; tar plcf - . ) | ( cd ${PREFIX}/share/nighthawk/data ; tar plvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/nighthawk
	${FIND} ${PREFIX}/share/nighthawk -type f -print | ${XARGS} ${CHMOD} 444
	${FIND} ${PREFIX}/share/nighthawk -type d -print | ${XARGS} ${CHMOD} 555
	${INSTALL_PROGRAM} ${WRKSRC}/src/nighthawk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src_sound/nighthawk_sound ${PREFIX}/bin
	${CHGRP} games ${PREFIX}/bin/nighthawk
	${CHMOD} g+s ${PREFIX}/bin/nighthawk
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/nighthawk/README
	${INSTALL} -o ${ROOT_USER} -g games -m 664 /dev/null /var/games/nighthawk.scores

.include "../../mk/bsd.pkg.mk"
