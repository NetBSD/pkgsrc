# $NetBSD: Makefile,v 1.13 2000/06/22 08:11:34 itohy Exp $
#

DISTNAME=		transfig.3.2.3
PKGNAME=		transfig-3.2.3
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/transfig/}

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
