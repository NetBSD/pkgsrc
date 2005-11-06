# $NetBSD: Makefile,v 1.3 2005/11/06 01:48:59 gdt Exp $
#

DISTNAME=		lprof-1.10.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lprof/}
PKGREVISION=		1

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://lprof.sourceforge.net/
COMMENT=		ICC Profile generation tool (for IT8.7 targets)

USE_TOOLS+=	gmake

MAKE_ENV+=	BASEDIR=${PREFIX} QTDIR=${PREFIX} QTDIR=${PREFIX}/qt3/lib
MAKE_ENV+=	LDFLAGS="-L${PREFIX}/lib -L${QTDIR} -R${PREFIX}/lib -R{$QTDIR}"

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
