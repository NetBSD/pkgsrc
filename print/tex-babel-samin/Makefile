# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:39 rillig Exp $

DISTNAME=	babel-samin
PKGNAME=	tex-${DISTNAME}-1.0c
TEXLIVE_REV=	30288

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-samin
COMMENT=	Babel support for Samin
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
