# $NetBSD: Makefile,v 1.2 2015/04/22 22:13:28 markd Exp $

DISTNAME=	endfloat
PKGNAME=	tex-${DISTNAME}-2.5d
TEXLIVE_REV=	24962

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Move floats to the end with markers where they belong
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb27
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
