# $NetBSD: Makefile,v 1.1 2025/02/07 21:45:41 adam Exp $

DISTNAME=	omemo-dr-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/omemo-dr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.gajim.org/gajim/omemo-dr
COMMENT=	OMEMO Double Ratchet
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65.0.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.0:../../devel/py-protobuf

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
