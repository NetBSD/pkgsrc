# $NetBSD: Makefile,v 1.13 2021/11/09 20:34:40 wiz Exp $

DISTNAME=	deprecation-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deprecation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://deprecation.readthedocs.io/
COMMENT=	Library to handle automated deprecations
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

PYTHON_VERSIONED_DEPENDENCIES+=	packaging

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
