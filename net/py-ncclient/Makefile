# $NetBSD: Makefile,v 1.2 2015/04/13 23:12:43 rodent Exp $

DISTNAME=	ncclient-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/n/ncclient/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/ncclient
COMMENT=	NETCONF Python client
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.7.7.1:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-setuptools>0.6:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml>3.0:../../textproc/py-lxml

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
