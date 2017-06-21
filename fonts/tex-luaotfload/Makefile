# $NetBSD: Makefile,v 1.5 2017/06/21 08:28:43 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-2.8.2
TEXLIVE_REV=	43194

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
