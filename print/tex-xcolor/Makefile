# $NetBSD: Makefile,v 1.5 2016/06/19 21:14:35 markd Exp $

DISTNAME=	xcolor
PKGNAME=	tex-${DISTNAME}-2.12
PKGREVISION=	1
TEXLIVE_REV=	41044

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Driver-independent color extensions for LaTeX and pdfLaTeX
LICENSE=	lppl-1.2

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
