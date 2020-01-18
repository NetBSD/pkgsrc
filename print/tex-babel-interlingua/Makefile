# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:37 rillig Exp $

DISTNAME=	babel-interlingua
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	30276

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-interlingua
COMMENT=	Babel support for Interlingua
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
