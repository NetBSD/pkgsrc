# $NetBSD: Makefile,v 1.6 2019/04/26 10:30:33 roy Exp $

DISTNAME=	scandir-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scandir/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benhoyt/scandir
COMMENT=	Better directory iterator and faster os.walk()
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.5+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
