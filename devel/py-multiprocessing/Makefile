# $NetBSD: Makefile,v 1.1.1.1 2010/11/02 19:20:16 drochner Exp $
#

DISTNAME=	multiprocessing-2.6.2.1
PKGNAME=	${PYPKGPREFIX}-multiprocessing-2.6.2.1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/m/multiprocessing/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/multiprocessing/
COMMENT=	Python threading package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

do-test:
	${PYTHONBIN} -c "from multiprocessing import tests;tests.test_main()"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
