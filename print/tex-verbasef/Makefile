# $NetBSD: Makefile,v 1.1.1.1 2011/07/14 22:08:29 minskim Exp $

DISTNAME=	verbasef
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	21922

MAINTAINER=	minskim@NetBSD.org
COMMENT=	VERBatim Automatic Splitting of External Files

CONFLICTS=	tex-ltxmisc<2010.21927
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ltxmisc>=2010.21927:../../print/tex-ltxmisc
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-here-[0-9]*:../../print/tex-here

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
