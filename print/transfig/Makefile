# $NetBSD: Makefile,v 1.25 2004/10/03 00:18:07 tv Exp $
#

DISTNAME=		transfig.3.2.4
PKGNAME=		transfig-3.2.4
PKGREVISION=		2
CATEGORIES=		graphics print
MASTER_SITES=		ftp://epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
COMMENT=		TeX document creation tool utilizing portable graphics

USE_BUILDLINK3=		YES
USE_IMAKE=		YES

.include "../../mk/bsd.prefs.mk"

# A default paper size is used only in the IBM-GL/HP-GL driver:
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
MAKE_ENV+=		DDA4="-DA4"
.endif

# We must use GNU make on Linux
.if ${OPSYS} == "Linux"
USE_GNU_TOOLS+=		make
.endif

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
