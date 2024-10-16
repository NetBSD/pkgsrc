# $NetBSD: Makefile,v 1.11 2024/10/16 02:12:11 markd Exp $

DISTNAME=	gns3-server-2.2.49
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gns3-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GNS3/gns3-server
COMMENT=	GNS3 network simulator - Server package
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9.5:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-cors>=0.7.0:../../www/py-aiohttp-cors
DEPENDS+=	${PYPKGPREFIX}-aiofiles>=24.1.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-distro>=1.9.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.23:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.4:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=2.12:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-psutil>=6.0.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.3:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-cpuinfo>=9.0.0:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-truststore>=0.9.1:../../security/py-truststore
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.4.0:../../misc/py-platformdirs

USE_PKG_RESOURCES=	yes

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gns3server/compute/docker/resources/bin/udhcpc
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gns3server/compute/docker/resources/etc/udhcpc/default.script
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gns3server/compute/docker/resources/init.sh

post-install:
	chmod -R go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3server

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
