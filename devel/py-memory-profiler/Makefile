# $NetBSD: Makefile,v 1.1 2017/09/29 21:14:48 joerg Exp $

DISTNAME=	memory_profiler-0.47
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S,_,-,}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/memory_profiler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/memory_profiler
COMMENT=	Python Memory Profiler
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
