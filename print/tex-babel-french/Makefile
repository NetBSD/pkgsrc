# $NetBSD: Makefile,v 1.21 2026/03/28 23:39:42 markd Exp $

DISTNAME=	babel-french
PKGNAME=	tex-${DISTNAME}-4.0e
TEXLIVE_REV=	78251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-french
COMMENT=	Babel contributed support for French
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel
DEPENDS+=	tex-carlisle-[0-9]*:../../print/tex-carlisle

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
