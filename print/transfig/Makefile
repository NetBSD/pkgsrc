# $NetBSD: Makefile,v 1.15 2001/02/17 17:51:58 wiz Exp $
#

DISTNAME=		transfig.3.2.3
PKGNAME=		transfig-3.2.3
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/transfig/}

MAINTAINER=		root@garbled.net
COMMENT=		TeX document creation tool utilizing portable graphics

DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		YES
USE_XPM=		YES

.include "../../mk/bsd.pkg.mk"
