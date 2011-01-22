# $NetBSD: Makefile,v 1.4 2011/01/22 23:15:17 minskim Exp $

DISTNAME=	amsrefs
PKGNAME=	tex-${DISTNAME}-2.09
PKGREVISION=	1
TEXLIVE_REV=	20249

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX-based replacement for BibTeX

CONFLICTS+=	tex-ams-[0-9]*
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
