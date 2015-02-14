# $NetBSD: Makefile,v 1.2 2015/02/14 22:56:08 nros Exp $

DISTNAME=	biblatex
PKGNAME=	tex-${DISTNAME}-1.7
PKGREVISION=	1
TEXLIVE_REV=	24596

MAINTAINER=	markd@NetBSD.org
COMMENT=	Bibliographies in LaTeX using BibTeX for sorting only
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-etoolbox>=2.1:../../devel/tex-etoolbox
DEPENDS+=	tex-logreq>=1.0:../../print/tex-logreq
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
