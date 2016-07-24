# $NetBSD: Makefile,v 1.2 2016/07/24 18:56:21 agc Exp $

DISTNAME=	gssapi-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=pythongssapi/}
GITHUB_PROJECT=	python-gssapi
GITHUB_TAG=     v1.2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/gssapi
COMMENT=	Low-level and high-level wrappers around GSSAPI C libraries
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

AUTO_MKDIRS=	yes

.include "../../lang/python/distutils.mk"

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
