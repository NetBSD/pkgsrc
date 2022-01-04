# $NetBSD: Makefile,v 1.6 2022/01/04 20:53:51 wiz Exp $

PKGREVISION= 1
.include "../../emulators/keystone/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings for keystone
LICENSE=	modified-bsd

PYSETUPSUBDIR=	bindings/python

EGG_NAME=	keystone_engine-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake

.include "../../emulators/keystone/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
