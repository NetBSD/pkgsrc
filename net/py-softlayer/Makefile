# $NetBSD: Makefile,v 1.22 2024/11/11 07:28:51 wiz Exp $

DISTNAME=	softlayer-6.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoftLayer/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/softlayer/softlayer-python
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

WHEEL_NAME=	SoftLayer-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.4:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prettytable>=2.5.0:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rich>=13.7.1:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24:../../www/py-urllib3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} slcli slcli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
