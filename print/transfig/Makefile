# $NetBSD: Makefile,v 1.6 1998/07/03 14:24:42 frueauf Exp $
#

DISTNAME=		transfig.3.2.1
PKGNAME=		transfig-3.2.1
WRKSRC=			${WRKDIR}/transfig.3.2.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig

MAINTAINER=		root@garbled.futureone.com

DEPENDS+=		xpm-3.4j:../../graphics/xpm
DEPENDS+=		jpeg-6a:../../graphics/jpeg

CONFLICTS=		transfig-3.2

USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
