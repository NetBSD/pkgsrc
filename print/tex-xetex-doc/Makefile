# $NetBSD: Makefile,v 1.9 2024/03/24 11:06:27 markd Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2024
TEXLIVE_REV=	70088

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xetex
COMMENT=	Documentation for tex-xetex
LICENSE=	x11

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
