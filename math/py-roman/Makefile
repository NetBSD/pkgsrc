# $NetBSD: Makefile,v 1.1.1.1 2011/10/05 07:43:12 obache Exp $
#

DISTNAME=	roman-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/r/roman/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/roman/
COMMENT=	Integer to Roman numerals converter for Python
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-docutils<=0.7

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
