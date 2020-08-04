# $NetBSD: Makefile,v 1.13 2020/08/04 18:05:21 adam Exp $

DISTNAME=	ncclient-0.6.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ncclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ncclient/ncclient
COMMENT=	NETCONF Python client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.15.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-setuptools>0.6:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-selectors2>=2.0.1:../../devel/py-selectors2
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
