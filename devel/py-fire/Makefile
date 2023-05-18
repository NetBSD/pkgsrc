# $NetBSD: Makefile,v 1.2 2023/05/18 12:52:51 wiz Exp $

DISTNAME=	fire-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fire/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://pypi.org/project/fire
COMMENT=	Python DFU tool for updating Nitrokeys' firmware
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
