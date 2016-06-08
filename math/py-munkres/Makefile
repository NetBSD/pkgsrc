# $NetBSD: Makefile,v 1.4 2016/06/08 17:43:35 wiz Exp $

DISTNAME=	munkres-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/munkres/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/munkres/
COMMENT=	Munkres algorithm for the Assignment Problem
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
REPLACE_PYTHON=	munkres.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
