# $NetBSD: Makefile,v 1.2 2010/11/02 19:25:04 drochner Exp $
#

DISTNAME=	numexpr-1.4.1
PKGNAME=	${PYPKGPREFIX}-numexpr-1.4.1
CATEGORIES=	math
MASTER_SITES=	http://numexpr.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numexpr.googlecode.com/
COMMENT=	Numerical expression evaluator for NumPy
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

do-test:
	${PYTHONBIN} -c "import numexpr; numexpr.test()"

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
