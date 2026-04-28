# $NetBSD: Makefile,v 1.40 2026/04/28 13:06:42 adam Exp $

# NB: pydantic expresses an exact dependency on pydantic-core.  While
# unfortunate, it is actually true, and pydantic with non-matching
# versions of pydantic-core fail to build matrix-synapse.
# https://github.com/pydantic/pydantic/issues/12189#issuecomment-3227083571
DISTNAME=	pydantic-2.13.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic
COMMENT=	Data validation and settings management using python type hints
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=22.5.0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-annotated-types>=0.6.0:../../lang/py-annotated-types
# We must express the exact dependency from pyproject.toml with
# respect to upstream's version, but allow for possible nbN versions.
DEPENDS+=	${PYPKGPREFIX}-pydantic-core>=2.46.3<2.46.4:../../devel/py-pydantic-core
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.1:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-typing-inspection>=0.4.2:../../devel/py-typing-inspection
TEST_DEPENDS+=	${PYPKGPREFIX}-cloudpickle-[0-9]*:../../converters/py-cloudpickle
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals-[0-9]*:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=2.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-faker>=18.13.0:../../devel/py-faker
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.23.0:../../textproc/py-jsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=4.0.0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-codspeed-[0-9]*:../../devel/py-test-codspeed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-examples-[0-9]*:../../devel/py-test-examples
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-run-parallel>=0.3.1:../../devel/py-test-run-parallel

USE_LANGUAGES=	# none

# TODO: import cloudpickle and test-examples
pre-test:
	${RM} -f ${WRKSRC}/tests/test_docs.py ${WRKSRC}/tests/test_pickle.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
