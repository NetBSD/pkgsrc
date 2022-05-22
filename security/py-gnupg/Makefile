# $NetBSD: Makefile,v 1.31 2022/05/22 12:17:38 adam Exp $

DISTNAME=	python-gnupg-0.4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.red-dove.com/python-gnupg/
COMMENT=	Wrapper for the Gnu Privacy Guard
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.29.0:../../devel/py-wheel
DEPENDS+=	gnupg2>=2.2.0:../../security/gnupg2

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
