# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:38 rillig Exp $

DISTNAME=	babel-romansh
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	30286

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-romansh
COMMENT=	Babel/Polyglossia support for the Romansh language
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
