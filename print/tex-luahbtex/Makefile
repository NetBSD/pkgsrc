# $NetBSD: Makefile,v 1.2 2024/03/24 10:47:24 markd Exp $

DISTNAME=	luahbtex
PKGNAME=	tex-${DISTNAME}-1.18.0
TEXLIVE_REV=	70015

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luatex
COMMENT=	LuaTeX with HarfBuzz library for glyph shaping
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_FORMATS+=	"luahbtex luahbtex language.def,language.dat.lua luatex.ini\\n"

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
