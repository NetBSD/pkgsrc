# $NetBSD: Makefile,v 1.3 2010/05/26 03:50:20 minskim Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.3
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Package for typesetting exam scripts

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
