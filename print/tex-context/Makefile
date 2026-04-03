# $NetBSD: Makefile,v 1.34 2026/04/03 05:50:40 markd Exp $

DISTNAME=	context
PKGNAME=	tex-${DISTNAME}-20260325
TEXLIVE_REV=	78526

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context
COMMENT=	The ConTeXt macro package

DEPENDS+=	tex-dejavu-[0-9]*:../../fonts/tex-dejavu
DEPENDS+=	tex-lm>=2.004nb1:../../fonts/tex-lm
DEPENDS+=	tex-lm-math-[0-9]*:../../fonts/tex-lm-math
DEPENDS+=	tex-metapost>=1.211:../../graphics/tex-metapost
DEPENDS+=	tex-mptopdf>=2010:../../graphics/tex-mptopdf
DEPENDS+=	tex-pdftex>=1.40.11:../../print/tex-pdftex
DEPENDS+=	web2c>=2010nb4:../../print/web2c
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

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

USE_TOOLS+=	sh:run

REPLACE_TEXLUA=	bin/mtxrun

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/context/lua/mtxrun.lua \
		${WRKSRC}/bin/mtxrun

.include "../../mk/bsd.pkg.mk"
