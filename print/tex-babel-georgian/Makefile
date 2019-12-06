# $NetBSD: Makefile,v 1.3 2019/12/06 20:18:53 markd Exp $

DISTNAME=	babel-georgian
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	45864

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel-georgian
COMMENT=	Babel support of documents written in Georgian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
