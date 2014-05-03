# $NetBSD: Makefile,v 1.1 2014/05/03 02:46:46 rodent Exp $

DISTNAME=	yuicompressor-2.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	https://pypi.python.org/packages/source/y/yuicompressor/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://bitbucket.org/sprat/yuicompressor
COMMENT=	YUI Compressor packaged for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
USE_JAVA=	run

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/yuicompressor \
		${DESTDIR}${PREFIX}/bin/yuicompressor${PYVERSSUFFIX}

.include "../../mk/java-vm.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
