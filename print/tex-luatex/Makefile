# $NetBSD: Makefile,v 1.30 2026/02/17 10:43:34 markd Exp $

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-1.21.0.76924
TEXLIVE_REV=	76924

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.luatex.org/
COMMENT=	LuaTeX basic definition package
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex>=0.60.1:../../print/luatex
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.14159265.12854:../../print/tex-plain
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"luatex luatex language.def,language.dat.lua luatex.ini\\ndviluatex luatex language.def,language.dat.lua dviluatex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dviluatex

.include "../../mk/bsd.pkg.mk"
