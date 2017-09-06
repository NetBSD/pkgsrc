# $NetBSD: Makefile,v 1.6 2017/09/06 16:49:31 wiz Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20160522
TEXLIVE_REV=	41409

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
