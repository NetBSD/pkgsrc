# $NetBSD: Makefile,v 1.10 2020/05/01 00:15:09 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20200103
TEXLIVE_REV=	53517

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
