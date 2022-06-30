# $NetBSD: Makefile,v 1.12 2022/06/30 11:18:50 nia Exp $

DISTNAME=	dupeguru-src-4.0.4_RC
PKGNAME=	${DISTNAME:S/-src//:S/_RC/rc1/}
PKGREVISION=	2
CATEGORIES=	sysutils
#MASTER_SITES=	https://github.com/arsenetar/dupeguru/releases/download/4.0.4/
MASTER_SITES=	${MASTER_SITE_GITHUB:=arsenetar/}
GITHUB_RELEASE=	4.0.4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dupeguru.voltaicideas.net/
COMMENT=	Find duplicate files
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-polib>=1.0.4:../../devel/py-polib
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3.4nb1:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-hsaudiotag3k-[0-9]*:../../audio/py-hsaudiotag3k
DEPENDS+=	${PYPKGPREFIX}-Send2Trash-[0-9]*:../../sysutils/py-Send2Trash

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c
USE_TOOLS=		gmake pax

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		run.py

MAKE_ENV+=	PYRCC5=pyrcc5-${PYVERSSUFFIX}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}

INSTALLATION_DIRS=	bin share/applications share/dupeguru

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${PYTHONBIN} build.py
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
