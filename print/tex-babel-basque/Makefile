# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:34 rillig Exp $

DISTNAME=	babel-basque
PKGNAME=	tex-${DISTNAME}-1.0f
TEXLIVE_REV=	30256

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-basque
COMMENT=	Babel contributed support for Basque
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
