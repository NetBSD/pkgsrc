# $NetBSD: Makefile,v 1.22 2023/04/01 22:16:41 markd Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-3.18
TEXLIVE_REV=	65346

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pstricks-base
COMMENT=	PostScript macros for TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-auto-pst-pdf-[0-9]*:../../graphics/tex-auto-pst-pdf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
