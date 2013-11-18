# $NetBSD: Makefile,v 1.18 2013/11/18 18:57:17 minskim Exp $

DISTNAME=	IEEEtran
PKGNAME=	tex-${DISTNAME}-1.8
TEXLIVE_REV=	28697

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
