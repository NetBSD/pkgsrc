# $NetBSD: Makefile,v 1.6 2021/12/08 16:04:05 adam Exp $

PKGREVISION= 1
.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-core-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-core/}

COMMENT=	Bridge between Python and Objective-C

# pyobjc_setup.py does not exist here
SUBST_NOOP_OK.pysetup=	yes

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
