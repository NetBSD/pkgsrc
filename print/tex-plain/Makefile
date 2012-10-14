# $NetBSD: Makefile,v 1.8 2012/10/14 21:53:34 minskim Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653.26647
TEXLIVE_REV=	26647

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The Plain TeX format

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
