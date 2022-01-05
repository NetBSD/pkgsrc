# $NetBSD: Makefile,v 1.14 2022/01/05 15:41:20 wiz Exp $

DISTNAME=	libtaxii-1.1.119
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
#MASTER_SITES=	${MASTER_SITE_PYPI:=l/libtaxii/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=TAXIIProject/}
GITHUB_PROJECT=	libtaxii

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://taxiiproject.github.io/
COMMENT=	Python library for handling TAXII Messages and Services
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.4.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
