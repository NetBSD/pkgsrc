# $NetBSD: Makefile,v 1.16 2011/12/14 19:42:15 minskim Exp $

DISTNAME=	pdftex
PKGNAME=	tex-${DISTNAME}-1.40.11
PKGREVISION=	5
TEXLIVE_REV=	24563

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX extension for direct creation of PDF

CONFLICTS+=	teTeX-bin<=3.0nb29
DEPENDS+=	tex-dvips-[0-9]*:../../print/tex-dvips
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"pdftex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini\\netex pdftex language.def -translate-file=cp227.tcx *etex.ini\\npdfetex pdftex language.def -translate-file=cp227.tcx *pdfetex.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/etex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfetex

.include "../../mk/bsd.pkg.mk"
