# $NetBSD: Makefile,v 1.18 2002/10/08 13:14:01 jlam Exp $
#

DISTNAME=		transfig.3.2.3d
PKGNAME=		transfig-3.2.3.4
PKGREVISION=		1
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/transfig/} \
			ftp://www-epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
COMMENT=		TeX document creation tool utilizing portable graphics

USE_IMAKE=		YES

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
