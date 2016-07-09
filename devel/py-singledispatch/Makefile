# $NetBSD: Makefile,v 1.4 2016/07/09 13:03:43 wiz Exp $

DISTNAME=	singledispatch-3.4.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/singledispatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/singledispatch
COMMENT=	Library brings functools.singledispatch from Python 3.4
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3.4+

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
