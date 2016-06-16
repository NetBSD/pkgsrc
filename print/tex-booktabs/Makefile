# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:00 markd Exp $

DISTNAME=	booktabs
PKGNAME=	tex-${DISTNAME}-1.618033
TEXLIVE_REV=	40846

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Publication quality tables in LaTeX
LICENSE=	gnu-gpl-v2

CONFLICTS=	teTeX-texmf<3.0nb33
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
