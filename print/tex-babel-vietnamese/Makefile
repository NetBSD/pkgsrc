# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:40 rillig Exp $

DISTNAME=	babel-vietnamese
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	39246

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-vietnamese
COMMENT=	Babel support for typesetting Vietnamese
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
