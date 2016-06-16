# $NetBSD: Makefile,v 1.3 2016/06/16 03:57:29 markd Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-2.7.2
TEXLIVE_REV=	40902

MAINTAINER=	minskim@NetBSD.org
COMMENT=	OpenType layout system for Plain TeX and LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/luaotfload/*
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
