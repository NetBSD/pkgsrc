# $NetBSD: Makefile,v 1.1 2012/10/21 17:54:51 minskim Exp $

DISTNAME=	psfrag
PKGNAME=	tex-${DISTNAME}-3.04
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replace strings in encapsulated PostScript figures

CONFLICTS+=	teTeX-texmf<=3.0nb37
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
