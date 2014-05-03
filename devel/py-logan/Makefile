# $NetBSD: Makefile,v 1.3 2014/05/03 12:54:36 rodent Exp $

DISTNAME=	logan-0.5.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/l/logan/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/dcramer/logan
COMMENT=	Toolkit for building standalone Django applications
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.5.9.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
