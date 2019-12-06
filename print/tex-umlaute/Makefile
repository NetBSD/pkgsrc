# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:38 markd Exp $

DISTNAME=	umlaute
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	German input encodings in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
