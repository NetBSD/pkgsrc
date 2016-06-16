# $NetBSD: Makefile,v 1.5 2016/06/16 04:06:15 markd Exp $

DISTNAME=	ptex
PKGNAME=	tex-${DISTNAME}-3.2pl41220
TEXLIVE_REV=	41220

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
DEPENDS+=	tex-pbibtex-base-[0-9]*:../../print/tex-pbibtex-base
DEPENDS+=	tex-ptex-base-[0-9]*:../../print/tex-ptex-base
DEPENDS+=	tex-ptex-fonts-[0-9]*:../../fonts/tex-ptex-fonts
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	web2c>=2010nb5:../../print/web2c

#PKG_SYSCONFSUBDIR=	texmf

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"ptex ptex - ptex.ini\\neptex eptex language.def *eptex.ini\\nplatex eptex language.dat *platex.ini\\n"
TEX_KANJIMAP_FILES+=	morisawa.map
#TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
#TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf eptex ${DESTDIR}${PREFIX}/bin/platex

.include "../../mk/bsd.pkg.mk"
