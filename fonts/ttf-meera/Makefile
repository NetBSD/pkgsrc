# $NetBSD: Makefile,v 1.1 2022/05/23 17:09:24 nikita Exp $

DISTNAME=	ttf-meera-${GITLAB_TAG}
PKGNAME=	ttf-meera-7.0.3.20191223
CATEGORIES=	fonts
MASTER_SITES=	https://gitlab.com/smc/fonts/${GITLAB_PROJECT}/-/archive/${GITLAB_TAG}/
GITLAB_PROJECT=	meera
GITLAB_LONGTAG=	aebe37081332d93e02a83a8649120401967fc379
GITLAB_TAG=	aebe3708

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://smc.org.in/fonts/meera
COMMENT=	Malayalam font in TTF format
LICENSE=	gnu-gpl-v3 OR ofl-v1.1 # gpl-v3 with font exception OR ofl 1.1

USE_LANGUAGES=		# none
PYTHON_FOR_BUILD_ONLY=	yes

WRKSRC=		${WRKDIR}/${GITLAB_PROJECT}-${GITLAB_TAG}-${GITLAB_LONGTAG}
USE_TOOLS+=	gmake

BUILD_DEPENDS+=	${PYPKGPREFIX}-fonttools-[0-9]*:../../fonts/py-fonttools

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
