# $NetBSD: Makefile,v 1.22 2026/01/04 19:56:20 adam Exp $

DISTNAME=	python-gammu-3.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
MASTER_SITES=	https://dl.cihar.com/python-gammu/
CATEGORIES=	comms

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wammu.eu/gammu/
COMMENT=	Python bindings for gammu
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

.include "../../comms/gammu/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
