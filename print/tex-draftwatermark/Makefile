# $NetBSD: Makefile,v 1.11 2024/03/20 10:01:36 markd Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-3.3
TEXLIVE_REV=	70393

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://ctan.org/pkg/draftwatermark
COMMENT=	Put a grey textual watermark on document pages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-everypage>=1.1:../../print/tex-everypage
DEPENDS+=	tex-graphics>=1.0o:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
