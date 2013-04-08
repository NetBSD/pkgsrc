# $NetBSD: Makefile,v 1.5 2013/04/08 11:17:13 rodent Exp $
#

DISTNAME=	crack-attack-sounds-1.1.14-58.noarch
PKGNAME=	crack-attack-sounds-1.1.14
CATEGORIES=	games
MASTER_SITES=	http://download.opensuse.org/distribution/10.3/repo/oss/suse/noarch/
EXTRACT_SUFX=	.rpm

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://www.miguev.net/background-music-for-crack-attack-119-v05/
COMMENT=	Music and sounds for crack-attack

WRKSRC=		${WRKDIR}/usr/share/games/crack-attack
USE_LANGUAGES=	# none
NO_BUILD=	yes
NO_CONFIGURE=	yes

DESTDATADIR=	${DESTDIR}${PREFIX}/share/crack-attack

do-install:
	${INSTALL_DATA_DIR} ${DESTDATADIR}
	set -e; cd ${WRKSRC}; \
	for dir in music sounds; do \
		${INSTALL_DATA_DIR} "${DESTDATADIR}/$$dir"; \
		${INSTALL_DATA} "$$dir"/* "${DESTDATADIR}/$$dir"; \
	done

.include "../../mk/bsd.pkg.mk"
