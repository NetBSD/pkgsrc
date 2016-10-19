# $NetBSD: Makefile,v 1.6 2016/10/19 12:45:00 wiz Exp $

DISTNAME=	hypothesis-3.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypothesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/hypothesis/
COMMENT=	Python library for property based testing
LICENSE=	mpl-2.0

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

USE_LANGUAGES=	# none

# check if these (unpackaged) modules are needed:
# py-xdis
# py-spark-parser
# py-uncompyle

# actual tests only in github distfile, but that needs py-test and
# py-test depends on py-hypothesis...

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
