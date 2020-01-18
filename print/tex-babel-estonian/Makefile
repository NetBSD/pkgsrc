# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:36 rillig Exp $

DISTNAME=	babel-estonian
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	38064

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-estonian
COMMENT=	Babel support for Estonian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
