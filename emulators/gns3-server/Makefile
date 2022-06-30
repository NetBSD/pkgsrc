# $NetBSD: Makefile,v 1.7 2022/06/30 11:18:22 nia Exp $

DISTNAME=	gns3-server-2.2.1
PKGREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gns3-server/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://github.com/GNS3/gns3-server
COMMENT=	GNS3 network simulator - Server package
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=2.2.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiohttp-cors>=0.7.0:../../www/py-aiohttp-cors
DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.4.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.10:../../devel/py-async_generator
DEPENDS+=	${PYPKGPREFIX}-distro>=1.3.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.6.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-raven>=5.23.0:../../www/py-raven
DEPENDS+=	${PYPKGPREFIX}-psutil>=3.0.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=3.0.1:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-zipstream>=1.1.4:../../archivers/py-zipstream

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gns3server/compute/docker/resources/init.sh
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/gns3server/compute/docker/resources/etc/udhcpc/default.script

# we have newer jsonschema and it seems fine
SUBST_CLASSES+=		inst
SUBST_STAGE.inst=	pre-configure
SUBST_FILES.inst=	requirements.txt
SUBST_SED.inst=		-e "s:jsonschema==2.6.0:jsonschema:"

post-install:
	chmod go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3server/compute/docker/resources/init.sh
	chmod go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3server/compute/docker/resources/etc/udhcpc/default.script
	chmod go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/gns3server/compute/docker/resources/bin/busybox

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"

.include "../../mk/bsd.pkg.mk"
