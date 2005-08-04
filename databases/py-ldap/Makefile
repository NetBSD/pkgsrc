# $NetBSD: Makefile,v 1.23 2005/08/04 11:17:04 drochner Exp $

DISTNAME=	python-ldap-2.0.9
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-ldap/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-ldap/
COMMENT=	LDAP client API for Python

PYTHON_VERSIONS_ACCEPTED=	21 22 23 24
PYDISTUTILSPKG=			yes

SUBST_CLASSES+=			setup
SUBST_STAGE.setup=		pre-configure
SUBST_FILES.setup=		setup.cfg
SUBST_SED.setup=		-e "s|/usr/local/openldap-REL_ENG_2_1|${BUILDLINK_PREFIX.cyrus-sasl}/lib ${BUILDLINK_PREFIX.openldap}|" 	\
				-e "s|/usr/local/cyrus-sasl/include|${BUILDLINK_PREFIX.cyrus-sasl}/include/sasl|"

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/cyrus-sasl2/buildlink3.mk"
.include "../../lang/python/extension.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == ""
SUBST_SED.setup+=		-e "s|crypto|& read|"
.endif

.include "../../mk/bsd.pkg.mk"
