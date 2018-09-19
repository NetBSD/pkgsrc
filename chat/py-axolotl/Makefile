# $NetBSD: Makefile,v 1.1 2018/09/19 20:39:52 nia Exp $

PKGNAME=	${PYPKGPREFIX}-axolotl-0.1.42
DISTNAME=	python-axolotl-${PKGVERSION}
CATEGORIES=	chat security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-axolotl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tgalal/python-axolotl
COMMENT=	Python port of the ratcheting forward secrecy protocol
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.0.0:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../chat/py-axolotl-curve25519/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
