# $NetBSD: Makefile,v 1.11 2024/06/06 14:48:28 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_core-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-core/}

COMMENT=	Bridge between Python and Objective-C

# pyobjc_setup.py does not exist here
SUBST_NOOP_OK.pysetup=	yes

# Must use system libffi (for ffi_find_closure_for_code_np()).
#.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
