# $NetBSD: Makefile,v 1.32 2017/07/03 17:13:11 adam Exp $

DISTNAME=	simplejson-3.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PYPI:=s/simplejson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder
LICENSE=	mit

USE_LANGUAGES=	c

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test -q

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
