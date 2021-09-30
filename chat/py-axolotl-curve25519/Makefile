# $NetBSD: Makefile,v 1.3 2021/09/30 18:56:14 adam Exp $

DISTNAME=	python-axolotl-curve25519-0.4.1.post2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
CATEGORIES=	chat security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-axolotl-curve25519/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tgalal/python-axolotl-curve25519
COMMENT=	Python wrapper for curve25519 with ed25519 signatures
LICENSE=	gnu-gpl-v3

.include "../../lang/python/egg.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
