# $NetBSD: Makefile,v 1.10 2003/05/01 09:43:42 jmmv Exp $

DISTNAME=	ldapsdk_12311998
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/mozilla
CATEGORIES=	devel databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

CONFLICTS+=	openldap*

USE_GMAKE=	yes
USE_PERL5=	build
USE_BUILDLINK2=	yes

PKG_SYSCONFSUBDIR=	ldapsdk
EGDIR=			${PREFIX}/share/examples/ldapsdk

SCRIPTS_ENV+=	EGDIR=${EGDIR}
SCRIPTS_ENV+=	GMAKE=${GMAKE}
SCRIPTS_ENV+=	LN=${LN}

do-configure:
	${ECHO} "PKG_SYSCONFDIR=${PKG_SYSCONFDIR}" >> ${WRKSRC}/config/rules.mk
	${ECHO} "EGDIR=${EGDIR}" >> ${WRKSRC}/config/rules.mk

do-build:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-build

do-install:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-install

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
