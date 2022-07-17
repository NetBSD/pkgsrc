# $NetBSD: Makefile,v 1.73 2022/07/17 09:51:33 wiz Exp $
#
# Changelog sometimes at: https://www.mercurial-scm.org/wiki/WhatsNew

DISTNAME=	mercurial-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

USE_TOOLS+=	gmake msgfmt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_SELF_CONFLICT=		yes

.include "version.mk"
.include "options.mk"

USE_TOOLS+=		bash:test
# Known test failures as of 6.2
# test-run-tests.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6661
# test-http-bad-server.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6643
# test-https.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6726
# test-removeemptydirs.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6587
# test-status-tracked-key.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6662
# test-revlog.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6716
# test-patchbomb-tls.t:
# https://bz.mercurial-scm.org/show_bug.cgi?id=6727
# test-demandimport.py:
# https://bz.mercurial-scm.org/show_bug.cgi?id=6680
#
# Ran 889 tests, 83 skipped, 8 failed.

TEST_TARGET=		tests
TEST_MAKE_FLAGS+=	PYTHON=${PYTHONBIN} TESTFLAGS=${_MAKE_JOBS:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README.rst  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
