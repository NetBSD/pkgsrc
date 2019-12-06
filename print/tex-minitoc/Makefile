# $NetBSD: Makefile,v 1.5 2019/12/06 20:22:02 markd Exp $

DISTNAME=	minitoc
PKGNAME=	tex-${DISTNAME}-62
TEXLIVE_REV=	48196

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/minitoc
COMMENT=	Produce a table of contents for each chapter, part or section
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cmsd>=2010:../../fonts/tex-cmsd
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-notoccite>=2009:../../print/tex-notoccite
DEPENDS+=	tex-placeins>=2.2:../../print/tex-placeins

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
