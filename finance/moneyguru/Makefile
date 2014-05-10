# $NetBSD: Makefile,v 1.6 2014/05/10 06:52:03 wiz Exp $
#
# any of ~* is fine, they are the same and just there for Ubuntu
# so moneyguru's built for all releases
DISTNAME=	2.7.1
PKGNAME=	moneyguru-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/hsoft/moneyguru/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hardcoded.net/moneyguru/
COMMENT=	Personal finance management application
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-qt4-[0-9]*:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

DIST_SUBDIR=	moneyguru
EXTRACT_USING=	bsdtar

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c
USE_TOOLS=	pax

PYTHON_VERSIONS_INCOMPATIBLE=	26 27 # 3.x only
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON+=	cocoa/waf
REPLACE_PYTHON+=	cocoa/wscript
REPLACE_PYTHON+=	psmtabbarcontrol/waf
REPLACE_PYTHON+=	psmtabbarcontrol/wscript
REPLACE_PYTHON+=	run_template_cocoa.py
REPLACE_PYTHON+=	run_template_qt.py

INSTALLATION_DIRS=	bin share/applications share/moneyguru

do-configure:
	cd ${WRKSRC} && ${PYTHONBIN} configure.py

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} build.py
	${CHMOD} +x ${WRKSRC}/run.py

do-install:
	cd ${WRKSRC} && pax -pp -rw ambuttonbar build cocoa cocoalib core data help hscommon images locale plugin_examples psmtabbarcontrol qt qtlib run.py ${DESTDIR}${PREFIX}/share/moneyguru
	${INSTALL_DATA} ${WRKSRC}/debian/moneyguru.desktop ${DESTDIR}${PREFIX}/share/applications
	${LN} -s ${DESTDIR}${PREFIX}/share/moneyguru/run.py ${DESTDIR}${PREFIX}/bin/moneyguru

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
