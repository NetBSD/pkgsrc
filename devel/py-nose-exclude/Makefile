# $NetBSD: Makefile,v 1.1 2016/01/02 11:00:12 wiz Exp $

DISTNAME=	nose-exclude-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nose-exclude/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/nose-exclude
COMMENT=	Exclude specific directories from nosetests runs
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
