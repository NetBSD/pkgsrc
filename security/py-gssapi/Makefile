# $NetBSD: Makefile,v 1.3 2016/07/24 19:08:23 wiz Exp $

DISTNAME=	gssapi-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gssapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/gssapi
COMMENT=	Low-level and high-level wrappers around GSSAPI C libraries
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

AUTO_MKDIRS=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # as of 1.2.0, self tests don't run

.include "../../lang/python/distutils.mk"

.if ${PYVERSSUFFIX} == "2.7"
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
