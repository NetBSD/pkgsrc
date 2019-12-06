# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:34 markd Exp $

DISTNAME=	extsizes
PKGNAME=	tex-${DISTNAME}-1.4a
TEXLIVE_REV=	17263

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extend the standard LaTeX classes' size options
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
