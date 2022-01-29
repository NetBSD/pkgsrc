# $NetBSD: Makefile,v 1.3 2022/01/29 08:48:41 wiz Exp $

DISTNAME=	collectd-haproxy-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-collectd-[0-9]*:../../sysutils/py-collectd

PYTHON_VERSIONED_DEPENDENCIES+=	flake8

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
