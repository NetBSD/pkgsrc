# $NetBSD: Makefile,v 1.4 2010/11/13 03:21:33 minskim Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-1.0
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	reed@reedmedia.net
COMMENT=	Textual watermark package for LaTeX

DEPENDS+=	tex-everypage>=1.1:../../print/tex-everypage
DEPENDS+=	tex-graphics>=1.0o:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
