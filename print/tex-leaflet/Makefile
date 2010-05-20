# $NetBSD: Makefile,v 1.2 2010/05/20 18:01:30 minskim Exp $

DISTNAME=	leaflet
PKGNAME=	tex-${DISTNAME}-1.0c
TEXLIVE_REV=	15878

MAINTAINER=	leot1990@users.sourceforge.net
COMMENT=	Create small handouts (flyers)

DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
