# $NetBSD: Makefile,v 1.14 2024/02/03 04:00:44 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20230805
TEXLIVE_REV=	68425

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
