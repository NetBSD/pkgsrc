# $NetBSD: Makefile,v 1.4 2024/03/21 10:17:55 markd Exp $

DISTNAME=	luajittex
PKGNAME=	tex-${DISTNAME}-1.18.0
TEXLIVE_REV=	70015

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/luatex
COMMENT=	LuaTeX with just-in-time (jit) compiler, with and without HarfBuzz
LICENSE=	gnu-gpl-v2

DEPENDS+=	luajittex-[0-9]*:../../print/luajittex
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data

TEX_FORMATS+=	"luajithbtex luajithbtex language.def,language.dat.lua luatex.ini\\nluajittex luajittex language.def,language.dat.lua luatex.ini\\n"

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
