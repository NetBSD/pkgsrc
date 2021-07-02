# $NetBSD: Makefile,v 1.56 2021/07/02 15:51:17 wiz Exp $
#
# Changelog sometimes at: https://www.mercurial-scm.org/wiki/WhatsNew

DISTNAME=	mercurial-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	https://www.mercurial-scm.org/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/
COMMENT=	Fast, lightweight source control management system
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
# via xmlrpc from python itself, used in mercurial/pycompat.py
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

TEST_DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
# with this dependency, two zip test cases start working
# https://bz.mercurial-scm.org/show_bug.cgi?id=4483
# https://bz.mercurial-scm.org/show_bug.cgi?id=4485
TEST_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

USE_TOOLS+=	gmake msgfmt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/mercurial

.include "version.mk"
.include "options.mk"

USE_TOOLS+=		bash:test
# Known test failures as of 5.8
# test-persistent-nodemap.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6523
#
# Ran 878 tests, 81 skipped, 1 failed.

TEST_TARGET=		tests
TEST_MAKE_FLAGS+=	PYTHON=${PYTHONBIN} TESTFLAGS=${_MAKE_JOBS:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README.rst  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
