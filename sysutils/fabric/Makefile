# $NetBSD: Makefile,v 1.57 2022/07/13 12:13:15 adam Exp $

DISTNAME=	fabric-2.7.0
CATEGORIES=	sysutils net python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Fabric/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://fabfile.org/
COMMENT=	Simple Pythonic remote deployment tool
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-invoke>=1.3:../../sysutils/py-invoke
DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
DEPENDS+=	${PYPKGPREFIX}-paramiko>=2.4:../../security/py-paramiko

USE_LANGUAGES=		# none
USE_PKG_RESOURCES=	yes
USE_TOOLS+=		pax

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
