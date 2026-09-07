# $NetBSD: Makefile,v 1.5 2026/09/07 12:16:39 adam Exp $

DISTNAME=	omemo_dr-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/omemo-dr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.gajim.org/gajim/omemo-dr
COMMENT=	OMEMO Double Ratchet
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.0:../../devel/py-protobuf

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
