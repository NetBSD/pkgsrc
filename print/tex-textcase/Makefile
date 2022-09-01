# $NetBSD: Makefile,v 1.5 2022/09/01 05:25:22 markd Exp $

DISTNAME=	textcase
PKGNAME=	tex-${DISTNAME}-1.03
TEXLIVE_REV=	63868

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://ctan.org/pkg/textcase
COMMENT=	Case conversion ignoring mathematics, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
