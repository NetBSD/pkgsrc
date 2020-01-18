# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:38 rillig Exp $

DISTNAME=	babel-polish
PKGNAME=	tex-${DISTNAME}-1.2l
TEXLIVE_REV=	30283

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-polish
COMMENT=	Babel support for Polish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
