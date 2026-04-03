# $NetBSD: Makefile,v 1.112 2026/04/03 16:11:18 wiz Exp $
#
# Changelog sometimes at: https://mercurial-scm.org/news

DISTNAME=	mercurial-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://www.mercurial-scm.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/
COMMENT=	Fast, lightweight source control management system
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.1.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_TOOLS+=	gmake msgfmt

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600	# msg_control
LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/mercurial

PYTHON_SELF_CONFLICT=		yes

.include "version.mk"

USE_TOOLS+=	bash:test
# Test status as of 7.2.1 as !root
# tests/test-revlog-mmapindex.t (race condition / buffer)

.if make(test)
# tries to build/install wheel
ALLOW_NETWORK_ACCESS=
.endif

post-build:
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} build-chg

post-install:
	cd ${WRKSRC} && PYTHON=${PYTHONBIN} make install-chg \
	    PREFIX=${DESTDIR}${PREFIX} \
	    MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README.rst  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

do-test:
	cd ${WRKSRC}/tests && ${SETENV} CARGO=/dev/null ${PYTHONBIN} run-tests.py -j${_MAKE_JOBS_N}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
