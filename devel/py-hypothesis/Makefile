# $NetBSD: Makefile,v 1.26 2017/08/04 04:57:52 adam Exp $

DISTNAME=	hypothesis-3.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/HypothesisWorks/hypothesis-python
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

# actual tests only in github distfile, but that needs py-test and
# py-test depends on py-hypothesis...

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
