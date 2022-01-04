# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:18 wiz Exp $

DISTNAME=	nose-exclude-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nose-exclude/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/nose-exclude
COMMENT=	Exclude specific directories from nosetests runs
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
