# $NetBSD: Makefile,v 1.1 2021/05/25 10:18:45 adam Exp $

DISTNAME=	enrich-1.2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enrich/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycontribs/enrich
COMMENT=	Extends py-rich
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-rich>=9.5.1:../../comms/py-rich

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-rich

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
