# $NetBSD: Makefile,v 1.3 2011/01/21 18:00:52 minskim Exp $

DISTNAME=	xltxtra
PKGNAME=	tex-${DISTNAME}-0.5e
TEXLIVE_REV=	19809

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extras files for LaTeX users of XeTeX

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-metalogo-[0-9]*:../../print/tex-metalogo
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
