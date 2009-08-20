# $NetBSD: Makefile,v 1.9 2009/08/20 17:15:21 epg Exp $
#

PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	simplejson-2.0.9
#PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplejson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c

PYDISTUTILSPKG=         yes

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test -q

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
