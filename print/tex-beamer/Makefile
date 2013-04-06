# $NetBSD: Makefile,v 1.3 2013/04/06 03:45:22 rodent Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.10
TEXLIVE_REV=	19443

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LaTeX class for producing presentations and slides

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
