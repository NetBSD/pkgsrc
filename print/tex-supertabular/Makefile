# $NetBSD: Makefile,v 1.1.1.1 2011/11/03 01:33:37 minskim Exp $

DISTNAME=	supertabular
PKGNAME=	tex-${DISTNAME}-4.1a
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Multi-page tables package

CONFLICTS=	teTeX-texmf<3.0nb33
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
