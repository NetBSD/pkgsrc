# $NetBSD: Makefile,v 1.17 2003/09/12 20:47:11 dmcmahill Exp $
#

DISTNAME=	gwave-20030804
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	Viewer for spice-like simulator output and other analog data

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/guile-gtk/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
