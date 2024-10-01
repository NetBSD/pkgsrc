# $NetBSD: Makefile,v 1.47 2024/10/01 01:08:28 gutteridge Exp $

DISTNAME=	scapy-2.6.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=secdev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scapy.net/
COMMENT=	Interactive packet manipulation program
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	tcpreplay-[0-9]*:../../net/tcpreplay

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39 # py-ipython

.include "options.mk"

# Upstream has an unorthodox means of defining the software version for Python
# packaging, where they advise packagers to force the correct value, as their
# tooling won't do it correctly for tagged releases.
SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	scapy/__init__.py
SUBST_VARS.version+=	PKGVERSION_NOREV
SUBST_MESSAGE.version=	Fixing version.

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

# Upstream mistakenly removed their scripting to install the man page.
post-install:
	${MV} ${WRKSRC}/doc/scapy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/scapy.1

DATE_VAL=	${DATE} "+%Y%m%d-%H%M%S"

# XXX this needs to be reworked to use scapy's run_tests with py-tox, which is
# the normal test suite mechanism now. Test coverage below isn't complete; it
# could also be tweaked with multiple -t plus -T to exclude irrelevant test
# components, like the one for Windows, but py-tox would probably be the
# simpler route.
do-test:
	cd ${WRKSRC}/test && ${SETENV} PYTHON=${PYTHONBIN} ./run_tests \
		-t regression.uts -f html -K ipv6 -l \
		-o /tmp/scapy_regression_test_${DATE_VAL:sh}.html

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
