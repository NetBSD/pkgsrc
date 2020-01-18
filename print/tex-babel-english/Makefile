# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:35 rillig Exp $

DISTNAME=	babel-english
PKGNAME=	tex-${DISTNAME}-3.3q
TEXLIVE_REV=	44495

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-english
COMMENT=	Babel support for English
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
