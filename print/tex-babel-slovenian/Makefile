# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:39 rillig Exp $

DISTNAME=	babel-slovenian
PKGNAME=	tex-${DISTNAME}-1.2i
TEXLIVE_REV=	30351

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-slovenian
COMMENT=	Babel support for typesetting Slovenian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
