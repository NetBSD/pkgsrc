# $NetBSD: Makefile,v 1.25 2020/01/26 12:55:00 rhialto Exp $

DISTNAME=	moneyguru-src-2.11.0
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	https://download.hardcoded.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hardcoded.net/moneyguru/
COMMENT=	Personal finance management application
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c
USE_TOOLS=	pax

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=			yes
REPLACE_PYTHON+=		run.py

INSTALLATION_DIRS=	bin share/applications share/moneyguru

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
BASE_ARCH!=	uname -m
.elif ${MACHINE_ARCH} == "x86_64"
BASE_ARCH=	amd64
.else
BASE_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=	BASE_ARCH=${BASE_ARCH:Q}

MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${PYTHONBIN} build.py
	${CHMOD} +x ${WRKSRC}/run.py

do-install:
	cd ${WRKSRC} && pax -pp -rw build core data help hscommon images locale qt qtlib run.py ${DESTDIR}${PREFIX}/share/moneyguru
	${INSTALL_DATA} ${WRKSRC}/debian/moneyguru.desktop ${DESTDIR}${PREFIX}/share/applications
	${LN} -s ${DESTDIR}${PREFIX}/share/moneyguru/run.py ${DESTDIR}${PREFIX}/bin/moneyguru

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
