# $NetBSD: Makefile,v 1.7 2019/05/07 12:28:42 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-2.96
TEXLIVE_REV=	50131

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/luaotfload
COMMENT=	OpenType layout system for Plain TeX and LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/luaotfload/*
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
