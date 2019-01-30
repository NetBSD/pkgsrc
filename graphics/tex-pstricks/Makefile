# $NetBSD: Makefile,v 1.13 2019/01/30 07:30:11 markd Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-2.94
TEXLIVE_REV=	49659

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pstricks-base
COMMENT=	PostScript macros for TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-auto-pst-pdf-[0-9]*:../../graphics/tex-auto-pst-pdf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
