# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:36 wiz Exp $

DISTNAME=	python-axolotl-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	chat security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-axolotl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tgalal/python-axolotl
COMMENT=	Python port of the ratcheting forward secrecy protocol
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-axolotl-curve25519>=0.4.1:../../chat/py-axolotl-curve25519
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.0.0:../../devel/py-protobuf

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=   27 # py-protobuf

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
