# $NetBSD: Makefile,v 1.4 2008/09/11 16:32:06 mjl Exp $
#

PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	simplejson-1.9.2
EGG_NAME=  ${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/s/simplejson/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	http://undefined.org/python/#simplejson
COMMENT=	Simplejson is a simple, fast, extensible JSON encoder/decoder

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=  c

PYDISTUTILSPKG=         yes
PYBINMODULE=    yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
