# $NetBSD: Makefile,v 1.72 2022/07/03 17:52:41 wiz Exp $
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

PYTHON_SELF_CONFLICT=	yes

.include "version.mk"
.include "options.mk"

USE_TOOLS+=		bash:test
# Known test failures as of 6.1.4
# test-run-tests.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6661
# test-http-bad-server.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6643
# test-https.t
# test-patchbomb-tls.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6645
# test-paths.t
# test-hgrc.t
# test-parseindex.t
# test-patchbomb-tls.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6646
# test-removeemptydirs.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6587
# test-revlog.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6716
# test-status-tracked-key.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6662
# test-demandimport.py:
# https://bz.mercurial-scm.org/show_bug.cgi?id=6680
#
# Ran 885 tests, 82 skipped, 11 failed.

TEST_TARGET=		tests
TEST_MAKE_FLAGS+=	PYTHON=${PYTHONBIN} TESTFLAGS=${_MAKE_JOBS:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README.rst  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
