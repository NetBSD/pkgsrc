# $NetBSD: Makefile,v 1.13 2023/04/08 06:31:22 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20230312
TEXLIVE_REV=	66580

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
