# $NetBSD: Makefile,v 1.11 2022/01/04 20:53:16 wiz Exp $

DISTNAME=	python-memcached-1.59
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-memcached/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.tummy.com/Community/software/python-memcached/
COMMENT=	Python memcached client
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	memcache.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
