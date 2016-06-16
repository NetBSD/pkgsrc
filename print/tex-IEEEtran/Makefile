# $NetBSD: Makefile,v 1.21 2016/06/16 04:06:09 markd Exp $

DISTNAME=	IEEEtran
PKGNAME=	tex-${DISTNAME}-1.8b
TEXLIVE_REV=	38238

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
