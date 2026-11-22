# $NetBSD: Makefile,v 1.19 2026/11/22 20:31:13 wiz Exp $

DISTNAME=	typer-0.29.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/typer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fastapi/typer
COMMENT=	Library for building CLI tools
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-annotated-doc>=0.0.2:../../textproc/py-annotated-doc
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.5.3:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-rich>=13.8.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-shellingham>=1.3.0:../../misc/py-shellingham
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.9.5:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.32.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	typer

# as of 0.29.2
#    1620 passed
#       7 failed
#         - tests/test_tutorial/test_options/test_help/test_tutorial004.py:31 test_help[tutorial004_non_an]
#         - tests/test_tutorial/test_options/test_help/test_tutorial004.py:31 test_help[tutorial004]
#         - tests/test_tutorial/test_parameter_types/test_enum/test_tutorial003.py:25 test_help[tutorial003_non_an]
#         - tests/test_tutorial/test_parameter_types/test_enum/test_tutorial003.py:25 test_help[tutorial003]
#         - tests/test_type_conversion.py:166 test_tuple_wrong_arity
#         - tests/test_types_file.py:138 test_binary_stderr
#         - tests/test_types_file.py:273 test_file_error
#       3 xfailed
#      39 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
