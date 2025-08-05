# $NetBSD: Makefile,v 1.42 2025/08/05 05:55:38 adam Exp $

DISTNAME=	python-gnupg-0.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.red-dove.com/python-gnupg/
COMMENT=	Wrapper for the Gnu Privacy Guard
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	gnupg2>=2.2.0:../../security/gnupg2

USE_LANGUAGES=	# none

TEST_ENV+=	GPGBINARY=${LOCALBASE}/bin/gpg2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
