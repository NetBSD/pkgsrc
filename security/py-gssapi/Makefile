# $NetBSD: Makefile,v 1.29 2025/04/19 07:58:22 wiz Exp $

DISTNAME=	gssapi-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gssapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pythongssapi/python-gssapi
COMMENT=	Low-level and high-level wrappers around GSSAPI C libraries
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
# unpackaged: k5test
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	mitkrb posix

# On Darwin, py-gssapi uses -framework GSS
.if ${OPSYS} != "Darwin"
PLIST.posix=	yes
.  include "../../mk/krb5.buildlink3.mk"
.  if ${KRB5_TYPE} == "mit-krb5"
PLIST.mitkrb=	yes
.  endif
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
