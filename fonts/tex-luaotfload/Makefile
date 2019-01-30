# $NetBSD: Makefile,v 1.6 2019/01/30 11:09:34 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-2.94
TEXLIVE_REV=	49747

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
