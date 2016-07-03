# $NetBSD: Makefile,v 1.15 2016/07/03 11:50:29 wiz Exp $

DISTNAME=	moneyguru-2.10.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=hsoft/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hardcoded.net/moneyguru/
COMMENT=	Personal finance management application
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c
USE_TOOLS=	pax

PYTHON_VERSIONS_INCOMPATIBLE=	27 33 # 3.4+ only
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON+=	cocoa/waf
REPLACE_PYTHON+=	cocoa/wscript
REPLACE_PYTHON+=	psmtabbarcontrol/waf
REPLACE_PYTHON+=	psmtabbarcontrol/wscript
REPLACE_PYTHON+=	run_template_cocoa.py
REPLACE_PYTHON+=	run_template_qt.py

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

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} build.py
	${CHMOD} +x ${WRKSRC}/run.py

do-install:
	cd ${WRKSRC} && pax -pp -rw ambuttonbar build cocoa cocoalib core data help hscommon images locale psmtabbarcontrol qt qtlib run.py ${DESTDIR}${PREFIX}/share/moneyguru
	${INSTALL_DATA} ${WRKSRC}/debian/moneyguru.desktop ${DESTDIR}${PREFIX}/share/applications
	${LN} -s ${DESTDIR}${PREFIX}/share/moneyguru/run.py ${DESTDIR}${PREFIX}/bin/moneyguru

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
