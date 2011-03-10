# $NetBSD: Makefile,v 1.1.1.1 2011/03/10 20:39:21 minskim Exp $

DISTNAME=	esint
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended set of integrals for Computer Modern

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
