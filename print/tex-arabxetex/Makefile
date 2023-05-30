# $NetBSD: Makefile,v 1.1 2023/05/30 11:47:51 markd Exp $

DISTNAME=	arabxetex
PKGNAME=	tex-${DISTNAME}-1.2.1
TEXLIVE_REV=	38299

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/arabxetex
COMMENT=	ArabTeX-like interface for XeLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
