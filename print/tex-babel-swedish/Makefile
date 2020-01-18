# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:40 rillig Exp $

DISTNAME=	babel-swedish
PKGNAME=	tex-${DISTNAME}-2.3d
TEXLIVE_REV=	30296

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-swedish
COMMENT=	Babel support for typesetting Swedish
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
