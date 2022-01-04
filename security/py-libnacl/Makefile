# $NetBSD: Makefile,v 1.2 2022/01/04 20:54:42 wiz Exp $

DISTNAME=	libnacl-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libnacl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saltstack/libnacl
COMMENT=	Python bindings for libsodium based on ctypes
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting PREFIX.
SUBST_FILES.prefix=	libnacl/__init__.py
SUBST_VARS.prefix=	PREFIX

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
