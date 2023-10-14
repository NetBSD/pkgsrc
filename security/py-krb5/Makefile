# $NetBSD: Makefile,v 1.3 2023/10/14 01:05:48 markd Exp $

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

PLIST_VARS+=	mitkrb heimdal

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
# On Darwin, use Heimdal.framework
MAKE_ENV+=	KRB5_KRB5CONFIG=/usr/bin/krb5-config
PLIST.heimdal=	yes
.else
MAKE_ENV+=	KRB5_KRB5CONFIG=${KRB5BASE}/bin/krb5-config
.  include "../../mk/krb5.buildlink3.mk"
.  if ${KRB5_TYPE} == "mit-krb5" 
PLIST.mitkrb=	yes 
.  else
PLIST.heimdal=	yes
.  endif
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
