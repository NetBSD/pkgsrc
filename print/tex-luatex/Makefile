# $NetBSD: Makefile,v 1.2 2009/04/14 02:29:01 minskim Exp $
# TeX Live Revision 10592

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.1
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMAT_NAMES+=	luatex
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/pdfluatex

.include "../../mk/bsd.pkg.mk"
