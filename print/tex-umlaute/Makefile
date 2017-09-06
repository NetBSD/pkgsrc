# $NetBSD: Makefile,v 1.3 2017/09/06 16:49:46 wiz Exp $

DISTNAME=	umlaute
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	German input encodings in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
