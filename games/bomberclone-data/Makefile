# $NetBSD: Makefile,v 1.3 2003/07/21 16:49:35 martti Exp $
#

DISTNAME=		bomberclone-data-0.7
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://bomberclone.sourceforge.net/
COMMENT=		Data files for Bomberclone

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/bomberclone
	cd ${WRKSRC}/data && ${PAX} -rw gfx maps player tileset \
		${PREFIX}/share/bomberclone

.include "../../mk/bsd.pkg.mk"
