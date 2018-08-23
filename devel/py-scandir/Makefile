# $NetBSD: Makefile,v 1.4 2018/08/23 11:31:51 adam Exp $

DISTNAME=	scandir-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scandir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benhoyt/scandir
COMMENT=	Better directory iterator and faster os.walk()
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	34 27 # included in 3.5+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
