# $NetBSD: Makefile,v 1.2 2002/09/09 01:19:36 markd Exp $

R_PKGNAME=	rpart
R_PKGVER=	3.1-7

MAINTAINER=	markd@netbsd.org
COMMENT=	Recursive partitioning

PLIST_SRC=	/dev/null

R_DEPENDS=	R>=1.5.0
DEPENDS+=	R-survival-*:../R-survival

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
