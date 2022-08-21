# $NetBSD: Makefile,v 1.1 2022/08/21 14:28:16 wiz Exp $

DISTNAME=	arabluatex
PKGNAME=	tex-${DISTNAME}-1.20
TEXLIVE_REV=	54512

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.robertalessi.net/arabluatex
COMMENT=	ArabTeX for LuaLaTeX
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v4.0

DEPENDS+=	tex-adjustbox-[0-9]*:../../print/tex-adjustbox
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
# xparse
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-lua-ul-[0-9]*:../../print/tex-lua-ul
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
DEPENDS+=	tex-luacolor-[0-9]*:../../print/tex-luacolor
# scrextend
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
