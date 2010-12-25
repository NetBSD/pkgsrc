# $NetBSD: Makefile,v 1.8 2010/12/25 05:25:30 minskim Exp $

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.60.1
PKGREVISION=	1
TEXLIVE_REV=	20552

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	luatex>=0.60.1:../../print/luatex
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.14159265.12854:../../print/tex-plain

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"luatex luatex language.def,language.dat.lua luatex.ini\\ndviluatex luatex language.def,language.dat.lua dviluatex.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dviluatex

.include "../../mk/bsd.pkg.mk"
