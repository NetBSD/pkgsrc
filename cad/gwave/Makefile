# $NetBSD: Makefile,v 1.16 2003/07/21 16:32:12 martti Exp $
#

DISTNAME=	gwave-20020122
PKGREVISION=	2
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
