# $NetBSD: Makefile,v 1.6 2017/06/07 10:21:34 he Exp $

DISTNAME=	ncclient-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ncclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/ncclient
COMMENT=	NETCONF Python client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.7.7.1:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-setuptools>0.6:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml>3.0:../../textproc/py-lxml

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
