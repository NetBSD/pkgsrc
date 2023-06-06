# $NetBSD: Makefile,v 1.3 2023/06/06 12:41:22 riastradh Exp $

DISTNAME=	anjalioldlipi-${GITLAB_TAG}
PKGREVISION=	1
PKGNAME=	anjalioldlipi-ttf-${GITLAB_TAG:S/Version//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITLAB:=smc/fonts/}
GITLAB_PROJECT=	anjalioldlipi
GITLAB_TAG=	Version7.1.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://smc.org.in/fonts/anjali
COMMENT=	Sans Serif Malayalam font in TTF format
LICENSE=	ofl-v1.1

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
	${INSTALL_DATA} ${WRKSRC}/build/AnjaliOldLipi-Regular.ttf ${DESTDIR}${FONTDIR}/AnjaliOldLipi-Regular.ttf
	${INSTALL_DATA} ${WRKSRC}/67-smc-anjalioldlipi.conf ${DESTDIR}${PREFIX}/share/fontconfig/conf.avail/

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
