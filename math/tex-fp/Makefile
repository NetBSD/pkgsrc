# $NetBSD: Makefile,v 1.2 2016/01/30 04:12:56 markd Exp $

DISTNAME=	fp
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Fixed point arithmetic
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
