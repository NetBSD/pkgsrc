# $NetBSD: Makefile,v 1.4 2019/12/06 20:21:46 markd Exp $

DISTNAME=	jurabib
PKGNAME=	tex-${DISTNAME}-0.6
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	BibTeX citation support for the humanities and legal texts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
