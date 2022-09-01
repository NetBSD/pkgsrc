# $NetBSD: Makefile,v 1.15 2022/09/01 10:56:49 markd Exp $

DISTNAME=	luaotfload.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.22
TEXLIVE_REV=	63611

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luaotfload
COMMENT=	Documentation for tex-luaotfload
LICENSE=	gnu-gpl-v2

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
