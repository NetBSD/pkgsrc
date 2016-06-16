# $NetBSD: Makefile,v 1.22 2016/06/16 04:06:14 markd Exp $

DISTNAME=	pdftex
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	41149

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pdftex
COMMENT=	TeX extension for direct creation of PDF
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-bin<=3.0nb29
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-updmap-map-[0-9]*:../../print/tex-updmap-map
DEPENDS+=	web2c-[0-9]*:../../print/web2c

USE_TOOLS+=	sh:run

REPLACE_SH=	bin/simpdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"pdftex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini\\netex pdftex language.def -translate-file=cp227.tcx *etex.ini\\npdfetex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini\\n"

TEX_MAP_FILES+= dummy-space.map

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/simpdftex/simpdftex \
		${WRKSRC}/bin/

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/etex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfetex

.include "../../mk/bsd.pkg.mk"
