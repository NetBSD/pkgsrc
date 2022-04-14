# $NetBSD: Makefile,v 1.24 2022/04/14 04:37:28 markd Exp $

DISTNAME=	ieeetran
PKGNAME=	tex-${DISTNAME}-1.8b
TEXLIVE_REV=	59672

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ieeetran
COMMENT=	LaTeX class for IEEE Transactions journals and conferences
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
