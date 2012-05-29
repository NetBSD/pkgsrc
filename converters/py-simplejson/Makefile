# $NetBSD: Makefile,v 1.12 2012/05/29 13:19:42 wiz Exp $
#

DISTNAME=	simplejson-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplejson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test -q

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
