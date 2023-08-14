# $NetBSD: Makefile,v 1.6 2023/08/14 05:25:14 wiz Exp $

DISTNAME=	collectd-haproxy-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=wglass/}
GITHUB_PROJECT=	collectd-haproxy
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/wglass/collectd-haproxy
COMMENT=	Plugin for collectd to gather HAProxy metrics
LICENSE=	mit

DEPENDS+=	haproxy>=1.4:../../net/haproxy
DEPENDS+=	${PYPKGPREFIX}-collectd-[0-9]*:../../sysutils/py-collectd
DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
