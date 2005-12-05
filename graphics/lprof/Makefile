# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:21 rillig Exp $
#

DISTNAME=		lprof-1.10.1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lprof/}
PKGREVISION=		5

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://lprof.sourceforge.net/
COMMENT=		ICC Profile generation tool (for IT8.7 targets)

USE_TOOLS+=	gmake

MAKE_ENV+=	BASEDIR=${PREFIX:Q} QTDIR=${PREFIX}/qt3
MAKE_ENV+=	LDFLAGS=${LDFLAGS:M*:Q}

BUILDLINK_DEPMETHOD.qt3-tools= build

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
