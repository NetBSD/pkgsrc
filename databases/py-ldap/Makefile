# $NetBSD: Makefile,v 1.20 2005/01/23 20:41:45 recht Exp $

DISTNAME=	python-ldap-2.0.2
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-ldap/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/python-ldap/
COMMENT=	LDAP client API for Python

PYTHON_VERSIONS_ACCEPTED=	21 22 23
PYDISTUTILSPKG=			yes
USE_BUILDLINK3=			yes

SUBST_CLASSES+=			setup
SUBST_STAGE.setup=		pre-configure
SUBST_FILES.setup=		${WRKSRC}/setup.cfg
SUBST_SED.setup=		-e "s|/usr/local/openldap-REL_ENG_2_1|${BUILDLINK_PREFIX.cyrus-sasl}/lib ${BUILDLINK_PREFIX.openldap}|" 	\
				-e "s|/usr/include/sasl|${BUILDLINK_PREFIX.cyrus-sasl}/include/sasl|"

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/cyrus-sasl2/buildlink3.mk"
.include "../../lang/python/extension.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == ""
SUBST_SED.setup+=		-e "s|crypto|& read|"
.endif

.include "../../mk/bsd.pkg.mk"
