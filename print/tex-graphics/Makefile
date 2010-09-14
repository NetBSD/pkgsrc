# $NetBSD: Makefile,v 1.4 2010/09/14 00:18:12 minskim Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0o
PKGREVISION=	1
TEXLIVE_REV=	19536

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Standard LaTeX graphics

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
