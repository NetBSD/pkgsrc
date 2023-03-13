# $NetBSD: Makefile,v 1.7 2023/03/13 13:55:43 schmonz Exp $

DISTNAME=	approval_utilities-8.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/approval_utilities/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Utilities for your production code that work well with approvaltests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-empty-files>=0.0.3:../../devel/py-empty-files
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.6.2:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUP=	setup.approval_utilities.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
