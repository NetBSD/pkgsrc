# $NetBSD: Makefile,v 1.1.1.1 2002/09/09 01:09:31 markd Exp $

R_PKGNAME=	lattice
R_PKGVER=	0.5-3

MAINTAINER=	markd@netbsd.org
COMMENT=	Implementation of Trellis Graphics

PLIST_SRC=	/dev/null

R_DEPENDS=	R>=1.5.0
DEPENDS+=	R-grid>=0.6:../R-grid

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
