# $NetBSD: Makefile,v 1.5 2015/04/22 09:47:01 markd Exp $

DISTNAME=	amsrefs
PKGNAME=	tex-${DISTNAME}-2.14
TEXLIVE_REV=	30646

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX-based replacement for BibTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ams-[0-9]*
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
