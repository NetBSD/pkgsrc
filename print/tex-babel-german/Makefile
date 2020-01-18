# $NetBSD: Makefile,v 1.6 2020/01/18 23:33:36 rillig Exp $

DISTNAME=	babel-german
PKGNAME=	tex-${DISTNAME}-2.11
TEXLIVE_REV=	49391

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-german
COMMENT=	Babel support for documents written in German
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
