# $NetBSD: Makefile,v 1.16 2017/09/08 02:47:24 markd Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653.43076
PKGREVISION=	2
TEXLIVE_REV=	43076

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/plain
COMMENT=	The Plain TeX format
#LICENSE=	knuth

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
