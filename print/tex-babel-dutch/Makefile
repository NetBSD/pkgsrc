# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:35 rillig Exp $

DISTNAME=	babel-dutch
PKGNAME=	tex-${DISTNAME}-3.8i
TEXLIVE_REV=	30263

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-dutch
COMMENT=	Babel contributed support for Dutch
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
