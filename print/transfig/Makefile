# $NetBSD: Makefile,v 1.10 1998/08/27 13:46:00 garbled Exp $
#

DISTNAME=		transfig.3.2.1
PKGNAME=		transfig-3.2.1
WRKSRC=			${WRKDIR}/transfig.3.2.1
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg

CONFLICTS=		transfig-3.2

USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
