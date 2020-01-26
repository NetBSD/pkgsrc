# $NetBSD: Makefile,v 1.23 2020/01/26 17:32:01 rillig Exp $

DISTNAME=	IEEEtran
PKGNAME=	tex-${DISTNAME}-1.8b
TEXLIVE_REV=	38238

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
