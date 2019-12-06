# $NetBSD: Makefile,v 1.3 2019/12/06 20:18:57 markd Exp $

DISTNAME=	babel-turkish
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	51560

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-turkish
COMMENT=	Babel support for Turkish documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
