# $NetBSD: Makefile,v 1.23 2003/11/10 03:06:12 danw Exp $
#

DISTNAME=		transfig.3.2.4
PKGNAME=		transfig-3.2.4
PKGREVISION=		1
CATEGORIES=		graphics print
MASTER_SITES=		ftp://epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
COMMENT=		TeX document creation tool utilizing portable graphics

USE_BUILDLINK2=		YES
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

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
