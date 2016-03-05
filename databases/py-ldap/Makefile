# $NetBSD: Makefile,v 1.66 2016/03/05 11:28:18 jperkin Exp $

DISTNAME=	python-ldap-2.4.25
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ldap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python-ldap.org/
COMMENT=	LDAP client API for Python
LICENSE=	python-software-foundation

PY_LDAP_LIBRARY_DIRS=		${BUILDLINK_PREFIX.openldap-client}/lib
PY_LDAP_INCLUDE_DIRS=		${BUILDLINK_PREFIX.openldap-client}/include
PY_LDAP_LIBS=			ldap_r lber ssl crypto
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 2.4.13

.include "options.mk"

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_FILES.setup=	setup.cfg
SUBST_SED.setup=	-e 's|@PY_LDAP_LIBRARY_DIRS@|${PY_LDAP_LIBRARY_DIRS:Q}|'
SUBST_SED.setup+=	-e 's|@PY_LDAP_INCLUDE_DIRS@|${PY_LDAP_INCLUDE_DIRS:Q}|'
SUBST_SED.setup+=	-e 's|@PY_LDAP_LIBS@|${PY_LDAP_LIBS}|'

USE_TOOLS+=		pax

REPLACE_PYTHON=		Lib/ldap/controls/readentry.py

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
