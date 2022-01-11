# $NetBSD: Makefile,v 1.4 2022/01/11 07:02:16 adam Exp $

DISTNAME=	enrich-1.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycontribs/enrich
COMMENT=	Extends py-rich
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.5.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-rich>=9.5.1:../../comms/py-rich

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-rich

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
