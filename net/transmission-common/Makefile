# $NetBSD: Makefile,v 1.6 2024/02/01 14:11:04 dogcow Exp $

PKGNAME=	transmission-common-${VERSION}
COMMENT=	Free, lightweight BitTorrent client (shared files)

# do not add nb* to this - 4.0.0nb1 does not conflict
CONFLICTS=	transmission-4.0.0

.include "../../net/transmission/Makefile.common"

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/transmission
USE_TOOLS+=		pax

do-install:
	cd ${WRKSRC}/web && ${PAX} -pp -rw public_html ${DESTDIR}${PREFIX}/share/transmission

.include "../../mk/bsd.pkg.mk"
