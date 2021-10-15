# $NetBSD: Makefile,v 1.4 2021/10/15 11:41:23 adam Exp $

DISTNAME=	leather-0.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/leather/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://leather.readthedocs.io/
COMMENT=	Python charting for 80% of humans
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
