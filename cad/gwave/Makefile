# $NetBSD: Makefile,v 1.13 2003/05/02 11:53:57 wiz Exp $
#

DISTNAME=	gwave-20020122
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/
COMMENT=	viewer for spice-like simulator output and other analog data

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/guile-gtk/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
