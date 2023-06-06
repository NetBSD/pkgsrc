# $NetBSD: Makefile,v 1.4 2023/06/06 12:41:23 riastradh Exp $

DISTNAME=	meera-${GITLAB_TAG}
PKGNAME=	ttf-meera-7.0.3.20191223
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITLAB:=smc/fonts/}
GITLAB_PROJECT=	meera
GITLAB_TAG=	aebe3708

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://smc.org.in/fonts/meera
COMMENT=	Malayalam font in TTF format
LICENSE=	gnu-gpl-v3 OR ofl-v1.1 # gpl-v3 with font exception OR ofl 1.1

USE_LANGUAGES=			# none
PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=	gmake

TOOL_DEPENDS+=	${PYPKGPREFIX}-fonttools-[0-9]*:../../fonts/py-fonttools
TOOL_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR} share/fontconfig/conf.avail

# make all would run tests, which requires the hb-view binary of
# harfbuzz to be available, which we currently don't build.
do-build:
	cd ${WRKSRC} && ${MAKE_ENV} make ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/Meera-Regular.ttf ${DESTDIR}${FONTDIR}/Meera-Regular.ttf
	${INSTALL_DATA} ${WRKSRC}/65-0-smc-meera.conf ${DESTDIR}${PREFIX}/share/fontconfig/conf.avail/

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
