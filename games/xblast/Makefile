# New ports collection makefile for:	xblast
# Version required:			2.2.1
# Date Created:				30 January 1998
# Whom:					root@garbled.futureone.com
#
# $NetBSD: Makefile,v 1.1 1998/02/08 23:37:13 hubertf Exp $
#

DISTNAME=		xblast-2.2
WRKSRC=			${WRKDIR}/XBlast-2.2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/multiplayer
DISTFILES=		xblast-2.2.tar.gz \
			xblast-2.2-to-2.2.1.tar.gz

MAINTAINER=		root@garbled.futureone.com

USE_IMAKE=		yes

post-patch:
	cd ${WRKSRC} ; ${SED} '/file_appl_def/s@/usr/lib/X11@'${PREFIX}'/lib/X11@' defaults.h >xx ; ${MV} xx defaults.h

.include <bsd.port.mk>
