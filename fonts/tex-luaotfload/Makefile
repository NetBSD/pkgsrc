# $NetBSD: Makefile,v 1.4 2016/08/07 07:17:37 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-2.7.3
TEXLIVE_REV=	41515

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
