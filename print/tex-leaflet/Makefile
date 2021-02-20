# $NetBSD: Makefile,v 1.9 2021/02/20 10:24:30 markd Exp $

DISTNAME=	leaflet
PKGNAME=	tex-${DISTNAME}-2.1a
TEXLIVE_REV=	56878

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
