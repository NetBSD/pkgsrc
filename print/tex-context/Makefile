# $NetBSD: Makefile,v 1.1.1.1 2010/06/16 23:59:12 minskim Exp $

DISTNAME=	context
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	16044

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The ConTeXt macro package

CONFLICTS+=	teTeX-bin<=3.0nb44
DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	tex-lm>=2.004nb1:../../fonts/tex-lm
DEPENDS+=	tex-pdftex>=1.40.10:../../print/tex-pdftex
DEPENDS+=	tex-supp-pdf>=2009:../../print/tex-supp-pdf
DEPENDS+=	web2c>=2009:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"cont-en pdftex cont-usr.tex -8bit *cont-en.ini\\nmptopdf pdftex - -translate-file=cp227.tcx mptopdf.tex\\nmetafun mpost - metafun.mp\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf mpost ${DESTDIR}${PREFIX}/bin/metafun
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mptopdf

.include "../../mk/bsd.pkg.mk"
