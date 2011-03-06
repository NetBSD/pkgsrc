# $NetBSD: Makefile,v 1.1.1.1 2011/03/06 21:13:25 minskim Exp $

DISTNAME=	eurofont
PKGNAME=	tex-${DISTNAME}-1.1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Provides a command that prints a euro symbol

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEX_MAP_FILES+=	zpeu.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
