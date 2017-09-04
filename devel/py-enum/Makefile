# $NetBSD: Makefile,v 1.3 2017/09/04 18:08:20 wiz Exp $

DISTNAME=	enum-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enum/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/enum/
COMMENT=	Robust enumerated type support in Python
LICENSE=	gnu-gpl-v3 OR python-software-foundation

USE_LANGUAGES=	# none

# From PYPI:
#
# Superseded by Python standard library.
#
# Python 3 now has in its standard library an enum implementation (also
# available for older Python versions as the third-party flufl.enum
# distribution) that supersedes this library.
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
