# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:40 rillig Exp $

DISTNAME=	babel-thai
PKGNAME=	tex-${DISTNAME}-1.0.0
TEXLIVE_REV=	30564

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-thai
COMMENT=	Support for Thai within babel
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
