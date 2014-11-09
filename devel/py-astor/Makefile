# $NetBSD: Makefile,v 1.2 2014/11/09 18:47:57 rodent Exp $

DISTNAME=	astor-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/a/astor/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/pmaupin/astor
COMMENT=	Read/rewrite/write Python ASTs
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
