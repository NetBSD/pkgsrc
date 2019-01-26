# $NetBSD: Makefile,v 1.7 2019/01/26 09:04:13 markd Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20181006
TEXLIVE_REV=	48863

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
