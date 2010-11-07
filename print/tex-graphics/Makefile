# $NetBSD: Makefile,v 1.5 2010/11/07 19:36:54 minskim Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0o
PKGREVISION=	1
TEXLIVE_REV=	20255

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Standard LaTeX graphics

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
