# $NetBSD: Makefile,v 1.6 2016/06/08 17:43:37 wiz Exp $

DISTNAME=	junos-eznc-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/junos-eznc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/junos-eznc/
COMMENT=	Python library to manage JunOS devices
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	${PYPKGPREFIX}-setuptools>0.6:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.15.2:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-ncclient>=0.4.6:../../net/py-ncclient
DEPENDS+=	${PYPKGPREFIX}-jinja2>2.7.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
