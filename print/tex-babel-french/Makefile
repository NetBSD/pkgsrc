# $NetBSD: Makefile,v 1.12 2020/01/18 23:33:36 rillig Exp $

DISTNAME=	babel-french
PKGNAME=	tex-${DISTNAME}-3.5e
TEXLIVE_REV=	50711

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-french
COMMENT=	Babel contributed support for French
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
