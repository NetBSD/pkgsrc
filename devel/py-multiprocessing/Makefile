# $NetBSD: Makefile,v 1.7 2014/05/09 07:37:02 wiz Exp $

DISTNAME=	multiprocessing-2.6.2.1
PKGNAME=	${PYPKGPREFIX}-multiprocessing-2.6.2.1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/multiprocessing/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/multiprocessing/
COMMENT=	Python threading package
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # does not make sense, python-3.x has it included

CFLAGS.SunOS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED=1

do-test:
	${PYTHONBIN} -c "from multiprocessing import tests;tests.test_main()"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
