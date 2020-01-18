# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:37 rillig Exp $

DISTNAME=	babel-latin
PKGNAME=	tex-${DISTNAME}-3.5
TEXLIVE_REV=	38173

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-latin
COMMENT=	Babel support for Latin
LICENSE=	lppl-1.0

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
