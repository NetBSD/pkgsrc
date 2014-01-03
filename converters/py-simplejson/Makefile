# $NetBSD: Makefile,v 1.18 2014/01/03 06:11:46 rodent Exp $
#

DISTNAME=	simplejson-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	https://pypi.python.org/packages/source/s/simplejson/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder
LICENSE=	mit

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	33 27 26
PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test -q

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
