# $NetBSD: Makefile,v 1.3 2025/10/09 08:01:58 wiz Exp $

DISTNAME=	omemo-dr-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/omemo-dr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.gajim.org/gajim/omemo-dr
COMMENT=	OMEMO Double Ratchet
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-protobuf>=4.21.0:../../devel/py-protobuf

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
