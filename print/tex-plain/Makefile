# $NetBSD: Makefile,v 1.18 2020/01/18 23:34:40 rillig Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653.43076
PKGREVISION=	2
TEXLIVE_REV=	43076

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/plain
COMMENT=	The Plain TeX format
#LICENSE=	knuth

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
