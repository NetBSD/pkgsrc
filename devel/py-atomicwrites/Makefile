# $NetBSD: Makefile,v 1.8 2016/08/22 14:08:43 wiz Exp $

DISTNAME=	atomicwrites-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atomicwrites/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/atomicwrites/
COMMENT=	Python module for atomic file writes on POSIX
LICENSE=	mit

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m pytest tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
