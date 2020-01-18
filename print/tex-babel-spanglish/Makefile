# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:39 rillig Exp $

DISTNAME=	babel-spanglish
PKGNAME=	tex-${DISTNAME}-0.3
TEXLIVE_REV=	37629

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-spanglish
COMMENT=	Simplified Spanish support for Babel
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
