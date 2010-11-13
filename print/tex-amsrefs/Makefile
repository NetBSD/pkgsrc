# $NetBSD: Makefile,v 1.3 2010/11/13 16:45:44 minskim Exp $

DISTNAME=	amsrefs
PKGNAME=	tex-${DISTNAME}-2.09
TEXLIVE_REV=	20249

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX-based replacement for BibTeX

CONFLICTS+=	tex-ams-*
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
