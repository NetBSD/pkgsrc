# $NetBSD: Makefile,v 1.7 2019/11/04 21:28:44 rillig Exp $

DISTNAME=	dupeguru-src-4.0.3
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	https://download.hardcoded.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hardcoded.net/dupeguru/
COMMENT=	Find duplicate files
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-polib>=1.0.4:../../devel/py-polib
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-hsaudiotag3k-[0-9]*:../../audio/py-hsaudiotag3k
DEPENDS+=	${PYPKGPREFIX}-Send2Trash-[0-9]*:../../sysutils/py-Send2Trash
#DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
#DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

EXTRACT_USING=	bsdtar

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c
USE_TOOLS=		gmake pax
#MAKE_JOBS_SAFE=	no

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		qt/run_template.py

INSTALLATION_DIRS=	bin share/applications share/dupeguru

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} build.py
	${CHMOD} +x ${WRKSRC}/run.py

do-install:
	rm -rf ${WRKSRC}/build/dupeguru-arch
	cd ${WRKSRC} && ${PYTHONBIN} package.py --arch
	cd ${WRKSRC}/build/dupeguru-arch && pax -pp -rw * ${DESTDIR}${PREFIX}/share/dupeguru
	${RM} -rf ${DESTDIR}${PREFIX}/share/dupeguru/hsaudiotag
	${RM} -rf ${DESTDIR}${PREFIX}/share/dupeguru/send2trash
	${LN} -s ${DESTDIR}${PREFIX}/share/dupeguru/run.py ${DESTDIR}${PREFIX}/bin/dupeguru
	${INSTALL_DATA} ${WRKSRC}/build/dupeguru-arch/dupeguru.desktop ${DESTDIR}${PREFIX}/share/applications
	${RM} -f ${DESTDIR}${PREFIX}/share/dupeguru/qt/platform.py.orig
	${RM} -f ${DESTDIR}${PREFIX}/share/dupeguru/hscommon/sphinxgen.py.orig

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
