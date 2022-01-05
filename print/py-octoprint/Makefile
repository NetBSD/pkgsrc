# $NetBSD: Makefile,v 1.7 2022/01/05 15:41:19 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-1.6.1
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=OctoPrint/}
GITHUB_PROJECT=	OctoPrint
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint/
COMMENT=	Snappy web interface for 3D printers
LICENSE=	gnu-agpl-v3

RCD_SCRIPTS=	octoprint

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-cachelib>=0.1:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-emoji>=0.5.4:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-feedparser>=6.0.2:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.0.7:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.2:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-assets>=2.0:../../www/py-flask-assets
DEPENDS+=	${PYPKGPREFIX}-flask-babel>=1.0:../../www/py-flask-babel
DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.5:../../www/py-flask-login
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-immutabledict>=2.0.0:../../devel/py-immutabledict
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-netaddr>=0.7.19:../../net/py-netaddr
DEPENDS+=	${PYPKGPREFIX}-netifaces>=0.10.9:../../net/py-netifaces
DEPENDS+=	${PYPKGPREFIX}-octoprint-filecheck>=2021.2.23:../../print/py-octoprint-filecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-firmwarecheck>=2021.2.4:../../print/py-octoprint-firmwarecheck
DEPENDS+=	${PYPKGPREFIX}-octoprint-pisupport>=2021.3.26:../../print/py-octoprint-pisupport
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.5.0.1:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-pylru>=1.2:../../devel/py-pylru
DEPENDS+=	${PYPKGPREFIX}-regex>2018.11.6:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-requests>=2.23.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sarge>=0.1.5:../../devel/py-sarge
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.8.5:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-sentry-sdk>=0.15.1:../../devel/py-sentry-sdk
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.1.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.14:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.10.4:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-websocket-client>=0.57:../../www/py-websocket-client
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=1.0.1:../../www/py-werkzeug
DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.12.1:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-zeroconf>=0.24:../../net/py-zeroconf
DEPENDS+=	${PYPKGPREFIX}-zipstream>=1.1.8:../../archivers/py-zipstream

USE_PKG_RESOURCES=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/octoprint \
		${DESTDIR}${PREFIX}/bin/octoprint-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
