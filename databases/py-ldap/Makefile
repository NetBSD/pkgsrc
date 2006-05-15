# $NetBSD: Makefile,v 1.30 2006/05/15 06:23:26 wiz Exp $

DISTNAME=	python-ldap-2.2.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-ldap/}

MAINTAINER=	ykomatsu@akaumigame.org
HOMEPAGE=	http://sourceforge.net/projects/python-ldap/
COMMENT=	LDAP client API for Python

PYTHON_VERSIONS_ACCEPTED=	23 24
PYDISTUTILSPKG=			yes

PY_LDAP_LIBRARY_DIRS=		${BUILDLINK_PREFIX.openldap}/lib
PY_LDAP_INCLUDE_DIRS=		${BUILDLINK_PREFIX.openldap}/include
PY_LDAP_LIBS=			ldap_r lber ssl crypto

.include "options.mk"

SUBST_CLASSES+=			setup
SUBST_STAGE.setup=		pre-configure
SUBST_FILES.setup=		setup.cfg
SUBST_SED.setup=		-e "s|@PY_LDAP_LIBRARY_DIRS@|${PY_LDAP_LIBRARY_DIRS}|"
SUBST_SED.setup+=		-e "s|@PY_LDAP_INCLUDE_DIRS@|${PY_LDAP_INCLUDE_DIRS}|"
SUBST_SED.setup+=		-e "s|@PY_LDAP_LIBS@|${PY_LDAP_LIBS}|"

PY_LDAP_DOCDIR=			${PREFIX}/share/doc/py-ldap

post-install:
	${INSTALL_DATA_DIR} ${PY_LDAP_DOCDIR}
	cd ${WRKSRC} && ${PAX} -rw CHANGES README INSTALL TODO Demo \
		${PY_LDAP_DOCDIR}

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
