# $NetBSD: Makefile,v 1.9 2020/01/18 23:33:44 rillig Exp $

DISTNAME=	caption
PKGNAME=	tex-${DISTNAME}-20181006
TEXLIVE_REV=	48863

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caption
COMMENT=	Customising captions in floating environments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
