# $NetBSD: Makefile,v 1.8 2022/04/16 00:38:00 markd Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2021
TEXLIVE_REV=	62387

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xetex
COMMENT=	Documentation for tex-xetex
LICENSE=	x11

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
