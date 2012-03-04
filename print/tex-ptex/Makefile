# $NetBSD: Makefile,v 1.3 2012/03/04 01:20:20 minskim Exp $

DISTNAME=	ptex
PKGNAME=	tex-${DISTNAME}-3.2
TEXLIVE_REV=	25342

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX system for publishing in Japanese

CONFLICTS+=	ja-ptex-bin-[0-9]*
DEPENDS+=	tex-adobemapping-[0-9]*:../../fonts/tex-adobemapping
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-ipaex-[0-9]*:../../fonts/tex-ipaex
DEPENDS+=	tex-japanese-[0-9]*:../../print/tex-japanese
DEPENDS+=	tex-japanese-otf-[0-9]*:../../fonts/tex-japanese-otf
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	web2c>=2010nb5:../../print/web2c

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/tex/ptexgeneric/config
CONF_FILES+=	${PREFIX}/share/texmf-dist/tex/ptexgeneric/config/language.ptx \
		${PKG_SYSCONFDIR}/tex/ptexgeneric/config/language.ptx

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"ptex ptex - ptex.ini\\neptex eptex language.def *eptex.ini\\nplatex eptex language.ptx *platex.ini\\n"
TEX_KANJIMAP_FILES+=	morisawa.map
TEX_KANJIMAP_FILES+=	ptex-@kanjiEmbed@@kanjiVariant@.map
TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf eptex ${DESTDIR}${PREFIX}/bin/platex

.include "../../mk/bsd.pkg.mk"
