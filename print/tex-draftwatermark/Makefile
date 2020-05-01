# $NetBSD: Makefile,v 1.9 2020/05/01 00:15:13 markd Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	54317

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://ctan.org/pkg/draftwatermark
COMMENT=	Textual watermark package for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-everypage>=1.1:../../print/tex-everypage
DEPENDS+=	tex-graphics>=1.0o:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
