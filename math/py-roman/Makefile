# $NetBSD: Makefile,v 1.4 2014/01/25 10:30:13 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
