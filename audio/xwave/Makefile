# New ports collection makefile for:	xwave
# Version required:			0.6
# Date created:				1998-02-21
# Whom:					hubertf@netbsd.org
#
# $NetBSD: Makefile,v 1.1 1998/02/21 22:43:46 hubertf Exp $
#

DISTNAME=		xwave-0.6
WRKSRC=			${WRKDIR}/xwave
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/editors

MAINTAINER=		hubertf@netbsd.org

USE_IMAKE=	yes

# XXX This line can be removed if NetBSD >1.3.1 is out - HF
XMKMF=	${SETENV} ${MAKE_ENV} xmkmf -a

post-patch:
	cd ${WRKSRC} ; ${MV} src/XWave src/XWave.ad
	cd ${WRKSRC} ; ${TOUCH} src/xwave.man

.include <bsd.port.mk>
