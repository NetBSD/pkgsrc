# $NetBSD: Makefile,v 1.26 2017/07/03 11:08:29 wiz Exp $

DISTNAME=	cffi-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cffi/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# needs 'make install' before running the tests
# many segfaults and 6 other test failures
# https://bitbucket.org/cffi/cffi/issues/321/cffi-191-segmentation-fault-during-self
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX} -v -k "not test_callback and not test_a_lot_of_callbacks and not test_wchar and not test_errno_callback and not test_functionptr_simple and not test_functionptr_voidptr_return and not test_functionptr_intptr_return and not test_functionptr_void_return and not test_cast_functionptr_and_int and not test_structptr_argument and not test_array_argument_as_list and not test_array_of_func_ptr and not test_function_pointer and not test_access_callback and not test_win32_calling_convention_0 and not test_ffi_callback and not test_array_length_from_constant and not test_some_integer_type_for_issue73 and not test_macro_var_callback"

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
