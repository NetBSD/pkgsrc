# $NetBSD: Makefile,v 1.6 1998/08/27 13:46:00 garbled Exp $
#

DISTNAME=		xblast-2.2
WRKSRC=			${WRKDIR}/XBlast-2.2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/multiplayer
DISTFILES=		xblast-2.2.tar.gz \
			xblast-2.2-to-2.2.1.tar.gz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.ikp.uni-koeln.de/~vogel/xblast/xblast.html

USE_IMAKE=		yes

post-patch:
	cd ${WRKSRC} ; ${SED} '/file_appl_def/s@/usr/lib/X11@'${PREFIX}'/lib/X11@' defaults.h >xx ; ${MV} xx defaults.h

.include "../../mk/bsd.pkg.mk"
