# New ports collection makefile for:	transfig
# Version required:			3.2
# Date Created:				30 January 1998
# Whom:					root@garbled.futureone.com
#
# $NetBSD: Makefile,v 1.1 1998/02/08 23:20:43 hubertf Exp $
#

DISTNAME=		transfig.3.2
PKGNAME=		transfig-3.2
WRKSRC=			${WRKDIR}/transfig.3.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig

MAINTAINER=		root@garbled.futureone.com

LIB_DEPENDS=		jpeg.7.:${PORTSDIR}/graphics/jpeg \
			Xpm.4.:${PORTSDIR}/graphics/xpm

USE_IMAKE=		yes

.include <bsd.port.mk>
