# $NetBSD: Makefile,v 1.1 2012/07/09 14:11:51 minskim Exp $

DISTNAME=	luaotfload
PKGNAME=	tex-${DISTNAME}-1.26
TEXLIVE_REV=	26718

MAINTAINER=	minskim@NetBSD.org
COMMENT=	OpenType layout system for Plain TeX and LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase

REPLACE_TEXLUA=	bin/mkluatexfontdb
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/luaotfload/mkluatexfontdb.lua \
		${WRKSRC}/bin/mkluatexfontdb
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
