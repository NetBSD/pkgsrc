# $NetBSD: Makefile,v 1.1 2023/05/18 12:01:03 nikita Exp $

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
.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 304
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
