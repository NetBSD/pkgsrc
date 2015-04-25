# $NetBSD: Makefile,v 1.2 2015/04/25 08:04:12 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-2.5.4
TEXLIVE_REV=	35328

MAINTAINER=	minskim@NetBSD.org
COMMENT=	OpenType layout system for Plain TeX and LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/luaotfload/*
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
