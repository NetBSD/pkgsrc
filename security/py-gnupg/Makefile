# $NetBSD: Makefile,v 1.40 2025/01/08 10:02:35 adam Exp $

DISTNAME=	python-gnupg-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.red-dove.com/python-gnupg/
COMMENT=	Wrapper for the Gnu Privacy Guard
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	gnupg2>=2.2.0:../../security/gnupg2

USE_LANGUAGES=	# none

TEST_ENV+=	GPGBINARY=${LOCALBASE}/bin/gpg2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
