# $NetBSD: Makefile,v 1.3 2009/04/27 16:14:07 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	pdftex
PKGNAME=	tex-${DISTNAME}-1.40.9.12785

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX extension for direct creation of PDF

CONFLICTS+=	teTeX-bin<=3.0nb29
DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../print/tex-bin-kpathsea
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMAT_NAMES+=	pdftex
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/etex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfetex

.include "../../mk/bsd.pkg.mk"
