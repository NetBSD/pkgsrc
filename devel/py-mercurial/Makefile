# $NetBSD: Makefile,v 1.95 2024/06/09 18:08:41 wiz Exp $
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

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_TOOLS+=	gmake msgfmt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_SELF_CONFLICT=		yes

.include "version.mk"

USE_TOOLS+=		bash:test
# Test status as of 6.7.3
# Ran 934 tests, 83 skipped, 1 failed.
# test-profile.t
# https://bz.mercurial-scm.org/show_bug.cgi?id=6846

TEST_TARGET=		tests
TEST_MAKE_FLAGS+=	PYTHON=${PYTHONBIN} TESTFLAGS=${_MAKE_JOBS:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README.rst  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} make tests ${TEST_MAKE_FLAGS}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
