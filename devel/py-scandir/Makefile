# $NetBSD: Makefile,v 1.3 2018/02/25 20:00:00 wiz Exp $

DISTNAME=	scandir-1.7
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
