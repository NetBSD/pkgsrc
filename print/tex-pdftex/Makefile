# $NetBSD: Makefile,v 1.30 2020/05/10 04:32:06 markd Exp $

DISTNAME=	pdftex
PKGNAME=	tex-${DISTNAME}-2020
PKGREVISION=	1
TEXLIVE_REV=	54227

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdftex
COMMENT=	TeX extension for direct creation of PDF
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-updmap-map-[0-9]*:../../print/tex-updmap-map
DEPENDS+=	web2c-[0-9]*:../../print/web2c

USE_TOOLS+=	sh:run

REPLACE_SH=	bin/simpdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"pdftex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini\\netex pdftex language.def -translate-file=cp227.tcx *etex.ini\\npdfetex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini\\n"

TEX_MAP_FILES+=	dummy-space.map

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/simpdftex/simpdftex \
		${WRKSRC}/bin/

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/etex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfetex

.include "../../mk/bsd.pkg.mk"
