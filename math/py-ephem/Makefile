# $NetBSD: Makefile,v 1.6 2010/09/20 09:52:14 obache Exp $
#

DISTNAME=		pyephem-3.7.3.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyephem/ephem/}
CATEGORIES=		geography
MASTER_SITES=		http://pypi.python.org/packages/source/p/pyephem/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rhodesmill.org/brandon/projects/pyephem.html
COMMENT=		Scientific-grade astronomical computations for Python
LICENSE=		gnu-lgpl-v3 OR gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${TEST_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} "test")

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
