# $NetBSD: Makefile,v 1.1.1.1 2010/07/24 13:21:49 gdt Exp $
#

DISTNAME=	pyutil-1.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyutil/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/pypi/pyutil
COMMENT=	Collection of mature utilities for Python programmers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# internal egg: setuptools_darcs
DEPENDS+=	${PYPKGPREFIX}-setuptools_trial:../../devel/py-setuptools_trial
DEPENDS+=	${PYPKGPREFIX}-twisted:../../net/py-twisted

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
