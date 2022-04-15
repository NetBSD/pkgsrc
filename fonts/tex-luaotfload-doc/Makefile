# $NetBSD: Makefile,v 1.14 2022/04/15 06:06:00 markd Exp $

DISTNAME=	luaotfload.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.21
TEXLIVE_REV=	62788

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luaotfload
COMMENT=	Documentation for tex-luaotfload
LICENSE=	gnu-gpl-v2

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
