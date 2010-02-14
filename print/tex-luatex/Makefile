# $NetBSD: Makefile,v 1.5 2010/02/14 23:45:44 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.2
PKGREVISION=	2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	luatex-[0-9]*:../../print/luatex
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.14159265.12854:../../print/tex-plain

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"luatex luatex language.def luatex.ini\\ndviluatex luatex language.def dviluatex.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dviluatex

.include "../../mk/bsd.pkg.mk"
