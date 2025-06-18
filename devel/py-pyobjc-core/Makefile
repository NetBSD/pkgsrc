# $NetBSD: Makefile,v 1.13 2025/06/18 15:24:46 adam Exp $

DISTNAME=	pyobjc_core-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-core/}

COMMENT=	Bridge between Python and Objective-C

.include "../../devel/py-pyobjc/Makefile.common"

# pyobjc_setup.py does not exist here
SUBST_NOOP_OK.pysetup=	yes

SUBST_CLASSES+=		suppress
SUBST_STAGE.suppress=	pre-configure
SUBST_MESSAGE.suppress=	Avoid [[clang::suppress]].
SUBST_FILES.suppress=	Modules/objc/test/coding.m
SUBST_FILES.suppress+=	Modules/objc/test/testbndl.m
SUBST_SED.suppress=	-e 's,\[\[clang::suppress\]\],CLANG_SUPPRESS,'

# Must use system libffi (for ffi_find_closure_for_code_np()).
#.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
