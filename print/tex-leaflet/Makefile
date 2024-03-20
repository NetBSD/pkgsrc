# $NetBSD: Makefile,v 1.10 2024/03/20 10:35:33 markd Exp $

DISTNAME=	leaflet
PKGNAME=	tex-${DISTNAME}-2.1c
TEXLIVE_REV=	70652

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	https://ctan.org/pkg/leaflet
COMMENT=	Create small handouts (flyers)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
