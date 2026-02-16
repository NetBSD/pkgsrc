# $NetBSD: Makefile,v 1.30 2026/02/16 18:16:21 adam Exp $

DISTNAME=	junos_eznc-2.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/junos-eznc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/py-junos-eznc
COMMENT=	Python library to manage JunOS devices
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-ncclient>=0.7.0:../../net/py-ncclient
DEPENDS+=	${PYPKGPREFIX}-paramiko>=3.5.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-scp>=0.7.0:../../net/py-scp
DEPENDS+=	${PYPKGPREFIX}-transitions-[0-9]*:../../devel/py-transitions
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yamlordereddictloader-[0-9]*:../../textproc/py-yamlordereddictloader

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
