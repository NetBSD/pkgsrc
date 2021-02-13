# $NetBSD: Makefile,v 1.11 2021/02/13 10:27:35 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20201026
TEXLIVE_REV=	56771

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
