# $NetBSD: Makefile,v 1.1.1.1 2010/09/10 22:15:37 minskim Exp $

DISTNAME=	tocbibind
PKGNAME=	tex-${DISTNAME}-1.5j
TEXLIVE_REV=	16882

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add bibliography/index/contents to Table of Contents

CONFLICTS+=	teTeX-texmf<=3.0nb27
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
