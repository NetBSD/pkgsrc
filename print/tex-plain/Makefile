# $NetBSD: Makefile,v 1.14 2017/06/21 11:45:57 markd Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653.43076
TEXLIVE_REV=	43076

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
