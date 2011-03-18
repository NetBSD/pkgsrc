# $NetBSD: Makefile,v 1.17 2011/03/18 23:29:38 minskim Exp $

DISTNAME=	IEEEtran
PKGNAME=	tex-${DISTNAME}-1.7a
PKGREVISION=	4
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
