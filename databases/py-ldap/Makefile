# $NetBSD: Makefile,v 1.49 2012/12/16 01:52:09 obache Exp $

DISTNAME=	python-ldap-2.4.10
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-ldap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python-ldap.org/
COMMENT=	LDAP client API for Python

EGG_NAME=	${DISTNAME:S/python-ldap/python_ldap/}

PY_LDAP_LIBRARY_DIRS=		${BUILDLINK_PREFIX.openldap-client}/lib
PY_LDAP_INCLUDE_DIRS=		${BUILDLINK_PREFIX.openldap-client}/include
PY_LDAP_LIBS=			ldap_r lber ssl crypto

.include "options.mk"

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_FILES.setup=	setup.cfg
SUBST_SED.setup=	-e 's|@PY_LDAP_LIBRARY_DIRS@|${PY_LDAP_LIBRARY_DIRS:Q}|'
SUBST_SED.setup+=	-e 's|@PY_LDAP_INCLUDE_DIRS@|${PY_LDAP_INCLUDE_DIRS:Q}|'
SUBST_SED.setup+=	-e 's|@PY_LDAP_LIBS@|${PY_LDAP_LIBS}|'

PY_LDAP_DOCDIR=		${PREFIX}/share/doc/py-ldap

USE_TOOLS+=		pax

INSTALLATION_DIRS=	${PY_LDAP_DOCDIR}

post-install:
	cd ${WRKSRC} && pax -s,.cvsignore,, -rw CHANGES README INSTALL TODO Demo \
		${DESTDIR}${PY_LDAP_DOCDIR}

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
