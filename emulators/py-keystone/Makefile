# $NetBSD: Makefile,v 1.4 2021/02/10 10:35:13 adam Exp $

.include "../../emulators/keystone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for keystone
LICENSE=	modified-bsd

PYSETUPSUBDIR=	bindings/python

EGG_NAME=	keystone_engine-${PKGVERSION_NOREV}

.include "../../emulators/keystone/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
