# $NetBSD: Makefile,v 1.20 2016/01/30 03:26:12 markd Exp $

DISTNAME=	IEEEtran
PKGNAME=	tex-${DISTNAME}-1.8a
TEXLIVE_REV=	35194

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
