# $NetBSD: Makefile,v 1.16 2001/08/06 15:41:13 wiz Exp $
#

DISTNAME=		transfig.3.2.3d
PKGNAME=		transfig-3.2.3.4
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/transfig/} \
			ftp://www-epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
COMMENT=		TeX document creation tool utilizing portable graphics

USE_IMAKE=		YES

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
