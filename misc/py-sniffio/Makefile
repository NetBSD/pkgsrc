# $NetBSD: Makefile,v 1.8 2024/11/11 07:28:45 wiz Exp $

DISTNAME=	sniffio-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sniffio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/sniffio
COMMENT=	Sniff out which async library your code is running under
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.4:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
