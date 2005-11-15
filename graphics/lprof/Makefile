# $NetBSD: Makefile,v 1.6 2005/11/15 19:49:26 gdt Exp $
#

DISTNAME=		lprof-1.10.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lprof/}
PKGREVISION=		4

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://lprof.sourceforge.net/
COMMENT=		ICC Profile generation tool (for IT8.7 targets)

USE_TOOLS+=	gmake

MAKE_ENV+=	BASEDIR=${PREFIX} QTDIR=${PREFIX}/qt3
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
