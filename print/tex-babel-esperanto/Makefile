# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:35 rillig Exp $

DISTNAME=	babel-esperanto
PKGNAME=	tex-${DISTNAME}-1.4t
TEXLIVE_REV=	30265

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-esperanto
COMMENT=	Babel support for Esperanto
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
