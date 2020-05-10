# $NetBSD: Makefile,v 1.16 2020/05/10 04:31:49 markd Exp $

DISTNAME=	metafont
# should be this instead:
#PKGNAME=	tex-${DISTNAME}-2.7182818.20140107
PKGNAME=	tex-${DISTNAME}-2020
PKGREVISION=	1
CATEGORIES=	fonts
TEXLIVE_REV=	54276

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
