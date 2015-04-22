# $NetBSD: Makefile,v 1.5 2015/04/22 10:51:05 markd Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	25045

MAINTAINER=	reed@reedmedia.net
COMMENT=	Textual watermark package for LaTeX

DEPENDS+=	tex-everypage>=1.1:../../print/tex-everypage
DEPENDS+=	tex-graphics>=1.0o:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
