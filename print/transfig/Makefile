# $NetBSD: Makefile,v 1.8 1998/07/04 09:19:06 mycroft Exp $
#

DISTNAME=		transfig.3.2.1
PKGNAME=		transfig-3.2.1
WRKSRC=			${WRKDIR}/transfig.3.2.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig

MAINTAINER=		root@garbled.futureone.com

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg

CONFLICTS=		transfig-3.2

USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
