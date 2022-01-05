# $NetBSD: Makefile,v 1.10 2022/01/05 22:05:50 wiz Exp $

DISTNAME=	munkres-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
#MASTER_SITES=	${MASTER_SITE_PYPI:=m/munkres/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=bmc/}
GITHUB_PROJECT=	munkres
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://software.clapper.org/munkres/
COMMENT=	Munkres algorithm for the Assignment Problem
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none
REPLACE_PYTHON=	munkres.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
