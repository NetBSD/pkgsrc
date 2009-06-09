# $NetBSD: Makefile,v 1.3 2009/06/09 22:23:33 minskim Exp $
# TeX Live Revision 12927

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	luatex-[0-9]*:../../print/luatex
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.14159265.12854:../../print/tex-plain

INSTALLATION_DIRS+=	bin

TEX_FORMAT_NAMES+=	luatex
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/pdfluatex

.include "../../mk/bsd.pkg.mk"
