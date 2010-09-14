# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:17 minskim Exp $

DISTNAME=	moreverb
PKGNAME=	tex-${DISTNAME}-2.3
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended verbatim

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
