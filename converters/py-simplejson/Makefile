# $NetBSD: Makefile,v 1.20 2014/01/25 10:29:58 wiz Exp $

DISTNAME=	simplejson-3.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	https://pypi.python.org/packages/source/s/simplejson/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder
LICENSE=	mit

USE_LANGUAGES=	c

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test -q

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
