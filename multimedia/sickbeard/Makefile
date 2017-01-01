# $NetBSD: Makefile,v 1.3 2017/01/01 14:43:49 wiz Exp $

DISTNAME=	sickbeard-507
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=midgetspy/}
GITHUB_PROJECT=	Sick-Beard
GITHUB_TAG=	build-${PKGVERSION_NOREV}

MAINTAINER=	js@heap.zone
HOMEPAGE=	http://sickbeard.com/
COMMENT=	PVR application to search and manage TV shows
# Licenses of all the installed files
LICENSE=	dynamic-drive-license AND gnu-agpl-v3 AND gnu-gpl-v3 AND gnu-lgpl-v2.1 AND mit AND modified-bsd AND python-software-foundation AND unlicense

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
DEPENDS+=	${PYPKGPREFIX}-cherrypy-[0-9]*:../../www/py-cherrypy
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson

WRKSRC=		${WRKDIR}/Sick-Beard-build-${PKGVERSION_NOREV}
NO_BUILD=	yes
USE_TOOLS=	pax

INSTALL_DIRS+=	autoProcessTV data lib sickbeard
INSTALL_FILES+=	SickBeard.py CHANGELOG.txt CONTRIBUTING.md COPYING.txt
AUTO_MKDIRS=	yes

PY_PATCHPLIST=			yes
REPLACE_PYTHON=			*.py */*.py */*/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-cheetah

BUILD_DEFS+=		VARBASE
OWN_DIRS_PERMS=		${VARBASE}/sickbeard /sickbeard sickbeard 750

PKG_GROUPS=		sickbeard
PKG_USERS=		sickbeard:sickbeard
PKG_HOME.sickbeard=	${PREFIX}/lib/sickbeard

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	sickbeard.sh
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_SED.paths+=	-e 's,@VARBASE@,${VARBASE},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/sickbeard.sh ${WRKSRC}/sickbeard.sh
	${RM} -rf ${WRKSRC}/lib/simplejson

do-install:
.for i in ${INSTALL_FILES} ${INSTALL_DIRS}
	cd ${WRKSRC} && pax -rw -pmp ${i} ${DESTDIR}${PREFIX}/lib/sickbeard/
.endfor
	${RM} -rf ${DESTDIR}${PREFIX}/lib/sickbeard/lib/tvdb_api/tests
	${INSTALL} -m 755 ${WRKSRC}/sickbeard.sh ${DESTDIR}${PREFIX}/bin/sickbeard

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
