# $NetBSD: Makefile,v 1.22 2017/09/04 17:41:11 adam Exp $

DISTNAME=	dulwich-0.18.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dulwich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dulwich.io/
COMMENT=	Python implementation of Git
LICENSE=	apache-2.0 OR gnu-gpl-v2

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-fastimport-[0-9]*:../../devel/py-fastimport
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
BUILD_DEPENDS+=	${PYPKGPREFIX}-geventhttpclient-[0-9]*:../../net/py-geventhttpclient

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} dul-receive-pack dul-receive-pack${PYVERSSUFFIX} && \
		${MV} dul-upload-pack dul-upload-pack${PYVERSSUFFIX} && \
		${MV} dulwich dulwich${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
