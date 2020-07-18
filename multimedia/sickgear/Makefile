# $NetBSD: Makefile,v 1.2 2020/07/18 23:22:49 js Exp $

DISTNAME=	release_${PKGVERSION_NOREV}
PKGNAME=	sickgear-0.21.39
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=SickGear/}
GITHUB_PROJECT=	SickGear
GITHUB_TAG=	release_${PKGVERSION_NOREV}
DIST_SUBDIR=	SickGear

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/SickGear/SickGear
COMMENT=	Management of TV shows and/or Anime
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah3

USE_TOOLS+=			pax
PYTHON_VERSIONS_ACCEPTED=	37 38

REPLACE_PYTHON+=	${WRKSRC}/sickgear.py
REPLACE_PYTHON+=	${WRKSRC}/SickBeard.py
REPLACE_PYTHON+=	${WRKSRC}/autoProcessTV/SickGear-NG/SickGear-NG.py
REPLACE_PYTHON+=	${WRKSRC}/autoProcessTV/autoProcessTV.py
REPLACE_PYTHON+=	${WRKSRC}/autoProcessTV/hellaToSickBeard.py
REPLACE_PYTHON+=	${WRKSRC}/autoProcessTV/mediaToSickbeard.py
REPLACE_PYTHON+=	${WRKSRC}/autoProcessTV/sabToSickBeard.py

CHECK_INTERPRETER_SKIP+=	lib/sickgear/init-scripts/init.gentoo

INSTALLATION_DIRS+=	bin lib/sickgear

# These are wrong all over the place.
CHECK_PERMS_SKIP=	*

do-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/sickgear >${WRKDIR}/sickgear

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/sickgear
	${INSTALL_SCRIPT} ${WRKDIR}/sickgear ${DESTDIR}${PREFIX}/bin/sickgear

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
