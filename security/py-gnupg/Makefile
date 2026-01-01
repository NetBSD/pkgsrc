# $NetBSD: Makefile,v 1.43 2026/01/01 09:09:00 adam Exp $

DISTNAME=	python_gnupg-0.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-gnupg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.red-dove.com/python-gnupg/
COMMENT=	Wrapper for the Gnu Privacy Guard
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	gnupg2>=2.2.0:../../security/gnupg2

USE_LANGUAGES=	# none

TEST_ENV+=	GPGBINARY=${LOCALBASE}/bin/gpg2

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
