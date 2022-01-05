# $NetBSD: Makefile,v 1.4 2022/01/05 15:41:08 wiz Exp $

DISTNAME=	unittest2pytest-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unittest2pytest/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/unittest2pytest
COMMENT=	Tool to rewrite Python unittest into pytest test cases
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} unittest2pytest unittest2pytest-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
