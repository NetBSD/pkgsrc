# $NetBSD: Makefile,v 1.7 2022/06/14 13:29:18 gdt Exp $

DISTNAME=	nodemcu-uploader-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nodemcu-uploader/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/kmpm/nodemcu-uploader/
COMMENT=	Tool to upload files to a nodemcu/ESP8266 device
LICENSE=	mit

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.10.10:../../devel/py-wrapt

USE_PKG_RESOURCES=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
