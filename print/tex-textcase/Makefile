# $NetBSD: Makefile,v 1.4 2020/05/05 12:01:04 markd Exp $

DISTNAME=	textcase
PKGNAME=	tex-${DISTNAME}-1.00
TEXLIVE_REV=	52092

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://ctan.org/pkg/textcase
COMMENT=	Case conversion ignoring mathematics, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
