# $NetBSD: Makefile,v 1.2 2010/02/08 11:54:25 obache Exp $
#

DISTNAME=	mpmath-0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://mpmath.googlecode.com/files/
EXTRACT_SUFX=	.zip
# XXX: all text file are DOS style.
# XXX: if future version install binary file,
# XXX: please consider to use another method.
EXTRACT_OPTS_ZIP=	-aaqo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mpmath/
COMMENT=	Python library for arbitrary-precision FP arithmetic
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PKG_DESTDIR_SUPPORT= user-destdir

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	${RUN} cd ${WRKSRC}/build/lib/mpmath/tests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
