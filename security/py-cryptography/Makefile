# $NetBSD: Makefile,v 1.1 2014/03/21 13:20:35 wiz Exp $

DISTNAME=	cryptography-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://pypi.python.org/packages/source/c/cryptography/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cryptography/
COMMENT=	Cryptographic recipes and primitives for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi>=0.8:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser>=2.10:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py33"
PLIST_SUBST+=   SONAME1=_cffi__xcd368b2dx4a8b9ec1.so
PLIST_SUBST+=   SONAME2=_cffi__xdf1872a9xf0ae7e21.so
PLIST_SUBST+=   SONAME3=_cffi__xf2e3c1f8xfba2f231.so
.elif ${PYPKGPREFIX} == "py27"
PLIST_SUBST+=   SONAME1=_cffi__x5fea2bacx4a8b9ec1.so
PLIST_SUBST+=   SONAME2=_cffi__x657b2f6exf0ae7e21.so
PLIST_SUBST+=   SONAME3=_cffi__xcfd0a060xfba2f231.so
.elif ${PYPKGPREFIX} == "py26"
PLIST_SUBST+=	SONAME1=_cffi__x63e6cd6axfba2f231.so
PLIST_SUBST+=	SONAME2=_cffi__xcc2cb6a8xf0ae7e21.so
PLIST_SUBST+=	SONAME3=_cffi__xe2e07463x4a8b9ec1.so
.endif

.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
