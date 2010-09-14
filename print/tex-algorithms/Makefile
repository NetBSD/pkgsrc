# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:08 minskim Exp $

DISTNAME=	algorithms
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	A suite of tools for typesetting algorithms in pseudo-code
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
