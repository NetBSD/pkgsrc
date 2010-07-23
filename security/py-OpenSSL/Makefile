# $NetBSD: Makefile,v 1.22 2010/07/23 23:04:27 gdt Exp $
#

DISTNAME=	pyOpenSSL-0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyOpenSSL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopenssl.sourceforge.net/
COMMENT=	Python interface to the OpenSSL library

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

# See PY_NO_EGG comments in ../../lang/python/extension.mk.
PY_NO_EGG=	no
EGG_NAME?=	${DISTNAME}
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
