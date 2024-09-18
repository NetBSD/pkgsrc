# $NetBSD: Makefile,v 1.9 2024/09/18 08:12:19 adam Exp $

DISTNAME=	octoprint-1.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint
COMMENT=	Snappy web interface for 3D printers
LICENSE=	gnu-agpl-v3

WHEEL_NAME=	OctoPrint-${PKGVERSION_NOREV}

RCD_SCRIPTS=	octoprint

# bundled_plugins
DEPENDS+=	${PYPKGPREFIX}-octoprint-filecheck>=2021.2.23:../../print/py-octoprint-filecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-firmwarecheck>=2021.10.11:../../print/py-octoprint-firmwarecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-pisupport>=2023.10.10:../../print/py-octoprint-pisupport
# core_deps
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi>=23.1.0:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-babel>=2.12.1:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-cachelib>=0.10.2:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorlog>=6.7.0:../../devel/py-colorlog
DEPENDS+=	${PYPKGPREFIX}-emoji>=2.10.1:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-feedparser>=6.0.11:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.2.0:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-flask>=2.2.3:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-assets>=2.1.0:../../www/py-flask-assets
DEPENDS+=	${PYPKGPREFIX}-flask-babel>=3.1.0:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-limiter>=3.5.0:../../www/py-flask-limiter
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.6.3:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-frozendict>=2.4.0:../../devel/py-frozendict
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.3:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.4.4:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.8:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.11.0:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.7.4:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-pathvalidate>=2.5.2:../../devel/py-pathvalidate
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.9.6:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9.8:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pydantic>=1.10.16:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-pylru>=1.2.1:../../devel/py-pylru
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sarge>=0.1.7:../../devel/py-sarge
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.10.0:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=1.40.0:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-watchdog>=2.3.1:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=1.6.1:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.2.3:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.15:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zeroconf>=0.127:../../net/py-zeroconf
DEPENDS+=	${PYPKGPREFIX}-zipstream-ng>=1.7.1:../../archivers/py-zipstream-ng
# vendored_deps
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.6.3:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-class-doc>=0.2.6:../../textproc/py-class-doc
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex
# plugin_deps
DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-ddt-[0-9]*:../../devel/py-ddt
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=5.1.0:../../devel/py-mock

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/octoprint \
		${DESTDIR}${PREFIX}/bin/octoprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
