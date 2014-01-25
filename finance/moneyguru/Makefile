# $NetBSD: Makefile,v 1.3 2014/01/25 10:30:07 wiz Exp $
#
# any of ~* is fine, they are the same and just there for Ubuntu
# so moneyguru's built for all releases
DISTNAME=	moneyguru_2.6.1~quantal
PKGNAME=	${DISTNAME:S/_/-/:S/~quantal//}
CATEGORIES=	finance
MASTER_SITES=	https://launchpad.net/~hsoft/+archive/ppa/+files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hardcoded.net/moneyguru/
COMMENT=	Personal finance management application
LICENSE=	fairware-license

DEPENDS+=	${PYPKGPREFIX}-qt4-[0-9]*:../../x11/py-qt4
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

FETCH_USING=	curl

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_LANGUAGES=	c
USE_TOOLS=	pax

PY_PATCHPLIST=			yes
REPLACE_PYTHON=			src/run.py

INSTALLATION_DIRS=	bin share/applications share/moneyguru

# remove pre-compiled file for wrong architecture
post-extract:
	${RM} ${WRKSRC}/src/core/model/_amount.cpython-32mu.so

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} build_modules.py
	${CHMOD} +x ${WRKSRC}/src/run.py

do-install:
	cd ${WRKSRC}/src && pax -pe -rw * ${DESTDIR}${PREFIX}/share/moneyguru
	${INSTALL_DATA} ${WRKSRC}/debian/moneyguru.desktop ${DESTDIR}${PREFIX}/share/applications
	${LN} -s ${DESTDIR}${PREFIX}/share/moneyguru/run.py ${DESTDIR}${PREFIX}/bin/moneyguru

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
