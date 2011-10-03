# $NetBSD: Makefile,v 1.2 2011/10/03 00:02:46 dholland Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# Does not like netbsd's mremap()
PYTHON_VERSIONS_INCOMPATIBLE=	24
.endif

do-test:
	${PYTHONBIN} -c "from multiprocessing import tests;tests.test_main()"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
