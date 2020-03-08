# $NetBSD: Makefile,v 1.4 2020/03/08 16:42:26 bsiegert Exp $

PKGREVISION= 1
.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-core-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-core/}

COMMENT=	Bridge between Python and Objective-C

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
