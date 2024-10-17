# $NetBSD: Makefile,v 1.51 2024/10/17 00:51:49 gutteridge Exp $

DISTNAME=	scapy-2.6.0
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-ipython

.include "options.mk"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	setup.py
SUBST_SED.config+=	-e "s|share/man|${PKGMANDIR}|g"
SUBST_MESSAGE.config=	Fixing man page paths.

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
