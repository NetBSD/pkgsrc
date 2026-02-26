# $NetBSD: Makefile,v 1.17 2026/02/26 11:25:09 adam Exp $

DISTNAME=	octoprint-1.11.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint
COMMENT=	Snappy web interface for 3D printers
LICENSE=	gnu-agpl-v3

RCD_SCRIPTS=	octoprint

DEPENDS+=	${PYPKGPREFIX}-octoprint-filecheck>=2024.11.12:../../print/py-octoprint-filecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-firmwarecheck>=2025.5.14:../../print/py-octoprint-firmwarecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-pisupport>=2023.10.10:../../print/py-octoprint-pisupport

DEPENDS+=	${PYPKGPREFIX}-Unidecode>0:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi>=23.1.0:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorlog>=6.9.0:../../devel/py-colorlog
DEPENDS+=	${PYPKGPREFIX}-emoji>=2.14.1:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-feedparser>=6.0.11:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.2.0:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-flask-assets>=2.1.0:../../www/py-flask-assets
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.6.3:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-frozendict>=2.4.6:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.3:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-limits>0:../../devel/py-limits
DEPENDS+=	${PYPKGPREFIX}-netaddr>=1.3.0:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.11.0:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathvalidate>=3.2.1:../../devel/py-pathvalidate
DEPENDS+=	${PYPKGPREFIX}-psutil>=6.1.1:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pylru>=1.2.1:../../devel/py-pylru
DEPENDS+=	${PYPKGPREFIX}-pytz>0:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-regex>0:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-sarge>=0.1.7.post1:../../devel/py-sarge
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.10.0:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=2.20.0:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wheel>0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-zipstream-ng>=1.8.0:../../archivers/py-zipstream-ng
# python_version >= "3.8"
DEPENDS+=	${PYPKGPREFIX}-babel>=2.16:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.8.0:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-cachelib>=0.13.0:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-flask>=3.0.3:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-babel>=4.0.0:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-limiter>=3.8:../../www/py-flask-limiter
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.7:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=10.5.0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.10.6:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-watchdog>=4.0.2:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.8.0:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=3.0.6:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.17.2:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.2:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zeroconf>=0.136.2:../../net/py-zeroconf
# python_version >= "3.9"
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.8.1:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.5.1:../../www/py-tornado

TEST_DEPENDS+=	${PYPKGPREFIX}-ddt-[0-9]*:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=5.1.0:../../devel/py-mock

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.4.4:../../devel/py-appdirs
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} octoprint octoprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
