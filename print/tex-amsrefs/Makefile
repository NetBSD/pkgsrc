# $NetBSD: Makefile,v 1.2 2010/05/19 22:59:13 minskim Exp $

DISTNAME=	amsrefs
PKGNAME=	tex-${DISTNAME}-2.03
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX-based replacement for BibTeX

CONFLICTS+=	tex-ams-*
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
