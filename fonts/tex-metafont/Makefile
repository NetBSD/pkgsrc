# $NetBSD: Makefile,v 1.17 2021/06/06 21:48:10 markd Exp $

DISTNAME=	metafont
# should be this instead:
#PKGNAME=	tex-${DISTNAME}-2.71828182
PKGNAME=	tex-${DISTNAME}-2021
CATEGORIES=	fonts
TEXLIVE_REV=	57972

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/metafont
COMMENT=	METAFONT system for specifying fonts
#LICENSE=	knuth

DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	tex-modes-[0-9]*:../../fonts/tex-modes

TEX_FORMATS=	"mf mf-nowin - -translate-file=cp227.tcx mf.ini\\n"

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
