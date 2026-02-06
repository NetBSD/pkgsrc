# $NetBSD: Makefile,v 1.23 2026/02/06 07:55:38 adam Exp $

DISTNAME=	python_gammu-3.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gammu/}
CATEGORIES=	comms python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wammu.eu/gammu/
COMMENT=	Python bindings for gammu
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

.include "../../comms/gammu/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
