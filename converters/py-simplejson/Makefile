# $NetBSD: Makefile,v 1.8 2009/03/05 18:51:27 joerg Exp $
#

PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	simplejson-1.9.2
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplejson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c

PYDISTUTILSPKG=         yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
