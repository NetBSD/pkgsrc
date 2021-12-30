# $NetBSD: Makefile,v 1.11 2021/12/30 13:05:39 adam Exp $

DISTNAME=	release_${PKGVERSION_NOREV}
PKGNAME=	sickgear-0.23.14
PKGREVISION=	2
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
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_TOOLS+=			pax
PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	sickgear.py
REPLACE_PYTHON+=	SickBeard.py
REPLACE_PYTHON+=	autoProcessTV/SickGear-NG/SickGear-NG.py
REPLACE_PYTHON+=	autoProcessTV/autoProcessTV.py
REPLACE_PYTHON+=	autoProcessTV/hellaToSickBeard.py
REPLACE_PYTHON+=	autoProcessTV/mediaToSickbeard.py
REPLACE_PYTHON+=	autoProcessTV/sabToSickBeard.py
REPLACE_PYTHON+=	autoProcessTV/sabToSickGear.py

CHECK_INTERPRETER_SKIP+=	lib/sickgear/init-scripts/init.gentoo

INSTALLATION_DIRS+=	bin lib/sickgear

# These are wrong all over the place.
CHECK_PERMS_SKIP=	*

do-build:
	find ${WRKSRC} -name '*.orig' -exec rm {} \;
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/sickgear >${WRKDIR}/sickgear

do-install:
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/sickgear
	${INSTALL_SCRIPT} ${WRKDIR}/sickgear ${DESTDIR}${PREFIX}/bin/sickgear

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
