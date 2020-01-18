# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:56 rillig Exp $

DISTNAME=	textcase
PKGNAME=	tex-${DISTNAME}-0.07
TEXLIVE_REV=	15878

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.ctan.org/tex-archive/macros/latex/contrib/textcase/
COMMENT=	Case conversion ignoring mathematics, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
