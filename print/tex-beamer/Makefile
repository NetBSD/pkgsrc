# $NetBSD: Makefile,v 1.2 2011/01/17 22:41:24 minskim Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.10
TEXLIVE_REV=	19443

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	A LaTeX class for producing presentations and slides

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
