# $NetBSD: Makefile,v 1.10 2023/11/19 17:02:49 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-core-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-core/}

COMMENT=	Bridge between Python and Objective-C

# pyobjc_setup.py does not exist here
SUBST_NOOP_OK.pysetup=	yes

# Must use system libffi (for ffi_find_closure_for_code_np()).
#.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
