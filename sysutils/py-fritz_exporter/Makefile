# $NetBSD: Makefile,v 1.4 2024/10/14 06:45:59 wiz Exp $

DISTNAME=	fritz_exporter-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=pdreker/}
# latest pypi distfile is older
GITHUB_TAG=	fritzexporter-v${PKGVERSION_NOREV}
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

WRKSRC=		${WRKDIR}/fritz_exporter-${GITHUB_TAG}

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
