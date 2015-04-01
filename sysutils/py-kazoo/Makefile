# $NetBSD: Makefile,v 1.2 2015/04/01 11:43:57 rodent Exp $

DISTNAME=	kazoo-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/k/kazoo/
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
