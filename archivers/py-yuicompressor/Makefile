# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:20 wiz Exp $

DISTNAME=	yuicompressor-2.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yuicompressor/}

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
