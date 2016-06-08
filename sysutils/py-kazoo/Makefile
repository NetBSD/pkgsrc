# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:39 wiz Exp $

DISTNAME=	kazoo-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kazoo/}
EXTRACT_SUFX=	.zip

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://kazoo.readthedocs.org/
COMMENT=	Higher level Zookeeper client
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "options.mk"

pre-install:
	${CHMOD} -x ${WRKSRC}/kazoo.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
