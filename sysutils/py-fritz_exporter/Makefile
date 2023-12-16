# $NetBSD: Makefile,v 1.2 2023/12/16 08:00:50 wiz Exp $

DISTNAME=	fritz_exporter-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=pdreker/}
# latest pypi distfile is older
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	fritz_exporter

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pdreker/fritz_exporter/
COMMENT=	Prometheus exporter for Fritz!Box home routers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-fritzconnection-[0-9]*:../../net/py-fritzconnection
DEPENDS+=	${PYPKGPREFIX}-prometheus_client-[0-9]*:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
