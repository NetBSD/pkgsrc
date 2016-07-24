# $NetBSD: Makefile,v 1.1 2016/07/24 18:49:35 agc Exp $

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

DEPENDS+=	${PYPKGPREFIX}-decorator-*:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-enum34-*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-six-*:../../lang/py-six

AUTO_MKDIRS=	yes

.include "../../lang/python/distutils.mk"

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
