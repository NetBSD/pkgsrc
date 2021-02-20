# $NetBSD: Makefile,v 1.10 2021/02/20 10:08:29 markd Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-3.0
TEXLIVE_REV=	57099

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://ctan.org/pkg/draftwatermark
COMMENT=	Textual watermark package for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-everypage>=1.1:../../print/tex-everypage
DEPENDS+=	tex-graphics>=1.0o:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
