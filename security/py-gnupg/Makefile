# $NetBSD: Makefile,v 1.30 2022/01/11 08:45:10 adam Exp $

DISTNAME=	python-gnupg-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.red-dove.com/python-gnupg/
COMMENT=	Wrapper for the Gnu Privacy Guard
LICENSE=	modified-bsd

DEPENDS+=	gnupg2>=2.2.0:../../security/gnupg2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
