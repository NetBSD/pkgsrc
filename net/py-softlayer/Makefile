# $NetBSD: Makefile,v 1.23 2025/01/25 11:43:43 adam Exp $

DISTNAME=	softlayer-6.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SoftLayer/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/softlayer/softlayer-python
COMMENT=	SoftLayer API bindings for Python
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/softl/SoftL/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.4:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-prettytable>=2.5.0:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rich>=13.9.4:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.24:../../www/py-urllib3

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} slcli slcli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
