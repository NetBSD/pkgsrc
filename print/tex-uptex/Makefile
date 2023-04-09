# $NetBSD: Makefile,v 1.2 2023/04/09 06:35:41 markd Exp $

DISTNAME=	uptex
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	66381

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uptex
COMMENT=	Unicode version of pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-uptex-base-[0-9]*:../../print/tex-uptex-base
DEPENDS+=	tex-uptex-fonts-[0-9]*:../../fonts/tex-uptex-fonts
DEPENDS+=	upmendex-[0-9]*:../../textproc/upmendex
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMATS+=	"uptex euptex - uptex.ini\\neuptex euptex language.def *euptex.ini\\n"

TEX_KANJIMAP_FILES+=	uptex-@jaEmbed@@jaVariant@.map
TEX_KANJIMAP_FILES+=	uptex-ko-@koEmbed@.map
TEX_KANJIMAP_FILES+=	uptex-sc-@scEmbed@.map
TEX_KANJIMAP_FILES+=	uptex-tc-@tcEmbed@.map

PLIST_SRC=	# none

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
