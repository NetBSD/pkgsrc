# $NetBSD: Makefile,v 1.13 2013/12/16 05:12:24 minskim Exp $

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.70.1pl30581
PKGREVISION=	1
TEXLIVE_REV=	30581

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package

DEPENDS+=	luatex>=0.60.1:../../print/luatex
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.14159265.12854:../../print/tex-plain

PKG_SYSCONFSUBDIR=	texmf

CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/texmfcnf.lua \
		${PKG_SYSCONFDIR}/web2c/texmfcnf.lua

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"luatex luatex language.def,language.dat.lua luatex.ini\\ndviluatex luatex language.def,language.dat.lua dviluatex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dviluatex

.include "../../mk/bsd.pkg.mk"
