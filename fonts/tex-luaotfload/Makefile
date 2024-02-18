# $NetBSD: Makefile,v 1.19 2024/02/18 10:19:17 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-3.27
TEXLIVE_REV=	69921

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luaotfload
COMMENT=	OpenType layout system for Plain TeX and LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-lua-uni-algos-[0-9]*:../../print/tex-lua-uni-algos
DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/luaotfload/*
TEX_TEXMF_DIRS=		${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
