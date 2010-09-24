# $NetBSD: Makefile,v 1.6 2010/09/24 21:16:27 minskim Exp $

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.60.1
TEXLIVE_REV=	19324

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
