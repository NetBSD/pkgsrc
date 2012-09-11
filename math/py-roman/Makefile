# $NetBSD: Makefile,v 1.3 2012/09/11 23:04:32 asau Exp $
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

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
