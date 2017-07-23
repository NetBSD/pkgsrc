# $NetBSD: Makefile,v 1.5 2017/07/23 18:39:51 adam Exp $

DISTNAME=	munkres-1.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/munkres/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/munkres/
COMMENT=	Munkres algorithm for the Assignment Problem
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
REPLACE_PYTHON=	munkres.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
