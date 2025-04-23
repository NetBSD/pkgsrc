# $NetBSD: Makefile,v 1.12 2025/04/23 12:45:09 adam Exp $

DISTNAME=	pyobjc_core-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-core/}

COMMENT=	Bridge between Python and Objective-C

.include "../../devel/py-pyobjc/Makefile.common"

# pyobjc_setup.py does not exist here
SUBST_NOOP_OK.pysetup=	yes

# Must use system libffi (for ffi_find_closure_for_code_np()).
#.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
