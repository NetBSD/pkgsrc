# $NetBSD: Makefile,v 1.4 1998/05/24 20:07:27 frueauf Exp $
#

DISTNAME=		transfig.3.2
PKGNAME=		transfig-3.2
WRKSRC=			${WRKDIR}/transfig.3.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/transfig

MAINTAINER=		root@garbled.futureone.com

DEPENDS+=		xpm-3.4j:../../graphics/xpm
DEPENDS+=		jpeg-6a:../../graphics/jpeg

USE_IMAKE=		yes

CAT1=			fig2dev.0 fig2ps2tex.0 pic2tpic.0 transfig.0

.include "../../mk/bsd.pkg.mk"
