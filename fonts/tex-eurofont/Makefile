# $NetBSD: Makefile,v 1.2 2011/11/06 08:43:29 minskim Exp $

DISTNAME=	eurofont
PKGNAME=	tex-${DISTNAME}-1.1.3
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Provides a command that prints a euro symbol

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEX_MAP_FILES+=	zpeu.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
