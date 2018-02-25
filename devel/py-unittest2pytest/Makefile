# $NetBSD: Makefile,v 1.1 2018/02/25 00:22:53 minskim Exp $

DISTNAME=	unittest2pytest-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unittest2pytest/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/unittest2pytest
COMMENT=	Tool to rewrite Python unittest into pytest test cases
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/unittest2pytest \
		${DESTDIR}${PREFIX}/bin/unittest2pytest${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
