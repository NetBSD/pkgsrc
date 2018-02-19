# $NetBSD: Makefile,v 1.3 2018/02/19 00:52:28 kamil Exp $

.include "../../emulators/keystone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for keystone
LICENSE=	modified-bsd

PYSETUPSUBDIR=	bindings/python

EGG_NAME=	${DISTNAME:R}

.include "../../emulators/keystone/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
