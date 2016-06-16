# $NetBSD: Makefile,v 1.13 2016/06/16 04:06:14 markd Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653.40274
TEXLIVE_REV=	40274

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/plain
COMMENT=	The Plain TeX format
#LICENSE=	knuth

CONFLICTS+=	teTeX-texmf<=3.0nb11
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-misc-[0-9]*:../../print/tex-misc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
