# $NetBSD: Makefile,v 1.6 2015/08/02 11:09:07 markd Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	37498

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ctan.org/pkg/draftwatermark
COMMENT=	Textual watermark package for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-everypage>=1.1:../../print/tex-everypage
DEPENDS+=	tex-graphics>=1.0o:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
