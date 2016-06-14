# $NetBSD: Makefile,v 1.2 2016/06/14 07:02:44 kamil Exp $

.include "../../emulators/keystone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for keystone
LICENSE=	modified-bsd

PYSETUPSUBDIR=	bindings/python

.include "../../emulators/keystone/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
