# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 15:47:34 wiz Exp $
#

DISTNAME=		bomberclone-data-0.7
WRKSRC=			${WRKDIR}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://bomberclone.sourceforge.net/
COMMENT=		data files for Bomberclone

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/bomberclone
	cd ${WRKSRC}/data && ${PAX} -rw gfx maps player tileset \
		${PREFIX}/share/bomberclone

.include "../../mk/bsd.pkg.mk"
