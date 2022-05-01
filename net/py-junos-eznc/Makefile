# $NetBSD: Makefile,v 1.17 2022/05/01 12:51:31 wiz Exp $

DISTNAME=	junos-eznc-2.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/junos-eznc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/py-junos-eznc
COMMENT=	Python library to manage JunOS devices
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.15.2:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-ncclient>=0.5.3:../../net/py-ncclient
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-scp>=0.7.0:../../net/py-scp
DEPENDS+=	${PYPKGPREFIX}-jxmlease-[0-9]*:../../textproc/py-jxmlease
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
