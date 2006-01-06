# $NetBSD: Makefile,v 1.25 2006/01/06 15:10:02 wiz Exp $

DISTNAME=	python-ldap-2.0.10
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	1
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
SUBST_SED.setup=		-e "s|@EXTRALIBS@|${BUILDLINK_PREFIX.cyrus-sasl}/lib ${BUILDLINK_PREFIX.openldap}/lib|" 	\
				-e "s|@EXTRAINCS@|${BUILDLINK_PREFIX.cyrus-sasl}/include/sasl ${BUILDLINK_PREFIX.openldap}/include|"

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/cyrus-sasl2/buildlink3.mk"
.include "../../lang/python/extension.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == ""
SUBST_SED.setup+=		-e "s|crypto|& read|"
.endif

.include "../../mk/bsd.pkg.mk"
