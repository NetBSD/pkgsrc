# $NetBSD: Makefile,v 1.3 2020/10/06 08:41:35 adam Exp $

DISTNAME=	leather-0.3.3
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
