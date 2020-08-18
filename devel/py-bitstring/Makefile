#	$NetBSD: Makefile,v 1.1 2020/08/18 20:13:03 riastradh Exp $

DISTNAME=	bitstring-3.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bitstring/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/bitstring
COMMENT=	Python module to create, manipulate, and analyze binary data
LICENSE=	mit

do-test:
	${RUN} cd ${WRKSRC}/test && \
	${SETENV} ${TEST_ENV} \
	${PYTHONBIN} -m unittest discover

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
