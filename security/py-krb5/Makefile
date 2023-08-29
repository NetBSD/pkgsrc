# $NetBSD: Makefile,v 1.2 2023/08/29 06:17:45 adam Exp $

DISTNAME=	krb5-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/krb5/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jborean93/pykrb5
COMMENT=	Kerberos API bindings for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.29:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
# On Darwin, use Heimdal.framework
MAKE_ENV+=	KRB5_KRB5CONFIG=/usr/bin/krb5-config
.else
MAKE_ENV+=	KRB5_KRB5CONFIG=${KRB5BASE}/bin/krb5-config
.  include "../../mk/krb5.buildlink3.mk"
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
