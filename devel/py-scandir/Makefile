# $NetBSD: Makefile,v 1.2 2017/10/04 12:25:45 adam Exp $

DISTNAME=	scandir-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scandir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/scandir
COMMENT=	Better directory iterator and faster os.walk()
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	34 27 # included in 3.5+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
