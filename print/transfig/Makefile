# $NetBSD: Makefile,v 1.2 1998/04/15 10:38:46 agc Exp $
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

.include "../../mk/bsd.pkg.mk"
