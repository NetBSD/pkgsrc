# $NetBSD: Makefile,v 1.20 2003/01/07 06:19:05 rh Exp $
#

DISTNAME=		transfig.3.2.4
PKGNAME=		transfig-3.2.4
CATEGORIES=		graphics print
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/transfig/} \
			ftp://epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
COMMENT=		TeX document creation tool utilizing portable graphics

USE_BUILDLINK2=		YES
USE_IMAKE=		YES

.include "../../mk/bsd.prefs.mk"

# A default paper size is used only in the IBM-GL/HP-GL driver:
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
MAKE_ENV+=		DDA4="-DA4"
.endif

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
