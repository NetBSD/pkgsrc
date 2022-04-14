# $NetBSD: Makefile,v 1.12 2022/04/14 06:32:00 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20220317
TEXLIVE_REV=	62757

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
