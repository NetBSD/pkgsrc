# $NetBSD: Makefile,v 1.2 1999/02/10 15:09:56 frueauf Exp $
#

DISTNAME=		nighthawk-2.1
WRKSRC=			${WRKDIR}/nighthawk
CATEGORIES=		x11 games
MASTER_SITES=		http://www.downunder.net.au/~jsno/rel/unix_projects/
EXTRACT_SUFX=		.tgz
PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		nighthawk-2.1a.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.downunder.net.au/~jsno/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_GMAKE=		YES
USE_X11=		YES

post-build:
	cd ${WRKSRC}/src_sound ; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} nighthawk_sound

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk
	${INSTALL_DATA_DIR} ${PREFIX}/share/nighthawk/data
	( cd ${WRKSRC}/data ; tar plcf - . ) | ( cd ${PREFIX}/share/nighthawk/data ; tar plvxf - )
	${CHOWN} -R ${SHAREOWN}.${SHAREGRP} ${PREFIX}/share/nighthawk
	find ${PREFIX}/share/nighthawk -type f -print | xargs ${CHMOD} 444
	find ${PREFIX}/share/nighthawk -type d -print | xargs ${CHMOD} 555
	${INSTALL_PROGRAM} ${WRKSRC}/src/nighthawk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src_sound/nighthawk_sound ${PREFIX}/bin
	${CHGRP} games ${PREFIX}/bin/nighthawk
	${CHMOD} g+s ${PREFIX}/bin/nighthawk
	${INSTALL} -o root -g games -m 664 /dev/null /var/games/nighthawk.scores

.include "../../mk/bsd.pkg.mk"
