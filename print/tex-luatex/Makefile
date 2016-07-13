# $NetBSD: Makefile,v 1.18 2016/07/13 11:17:21 markd Exp $

DISTNAME=	luatex
PKGNAME=	tex-${DISTNAME}-0.95
PKGREVISION=	1
TEXLIVE_REV=	40963

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	LuaTeX basic definition package
LICENSE=	gnu-gpl-v2

DEPENDS+=	luatex>=0.60.1:../../print/luatex
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.14159265.12854:../../print/tex-plain
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data

#
# A double-slash (//) in the kpathsea paths has a special
# interpretation, it will cause kpathsea to consider all
# subdirectories recursively at that point in the path.  Normally
# double-slashes and trailing slashes will not be present in these
# variables, but if they are there the resulting behaviour is so
# unexpected, expensive, and difficult to diagnose that it is worth
# going to extra effort to clean them out here.
#
SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting texmf directories.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texmf-dist/web2c/texmfcnf.lua
SUBST_SED.texmfdir+=	-e 's,@VARBASE@,${VARBASE:C;///*;/;g:C;/$;;},'
SUBST_SED.texmfdir+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:C;///*;/;g:C;/$;;},'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=	VARBASE
CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/texmfcnf.lua \
		${PKG_SYSCONFDIR}/texmfcnf.lua

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"luatex luatex language.def,language.dat.lua luatex.ini\\ndviluatex luatex language.def,language.dat.lua dviluatex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dviluatex

.include "../../mk/bsd.pkg.mk"
