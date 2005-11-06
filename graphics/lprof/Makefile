# $NetBSD: Makefile,v 1.1.1.1 2005/11/06 00:51:48 gdt Exp $
#

DISTNAME=		lprof-1.10.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lprof/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://lprof.sourceforge.net/
COMMENT=		ICC Profile generation tool (for IT8.7 targets)

USE_TOOLS+=	gmake

MAKE_ENV+=	QTDIR=${PREFIX} BASEDIR=${PREFIX}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
