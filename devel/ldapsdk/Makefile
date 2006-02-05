# $NetBSD: Makefile,v 1.21 2006/02/05 23:08:44 joerg Exp $

DISTNAME=	ldapsdk_12311998
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	devel databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

CONFLICTS+=	openldap-[0-9]*

WRKSRC=		${WRKDIR}/mozilla
USE_TOOLS+=	gmake perl

PKG_SYSCONFSUBDIR=	ldapsdk
EGDIR=			${PREFIX}/share/examples/ldapsdk

SCRIPTS_ENV+=	EGDIR=${EGDIR}
SCRIPTS_ENV+=	GMAKE=${GMAKE}
SCRIPTS_ENV+=	LN=${LN}

post-extract:
	${LN} -s FreeBSD.mk ${WRKSRC}/config/DragonFly.mk

do-configure:
	${ECHO} "PKG_SYSCONFDIR=${PKG_SYSCONFDIR}" >> ${WRKSRC}/config/rules.mk
	${ECHO} "EGDIR=${EGDIR}" >> ${WRKSRC}/config/rules.mk

do-build:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-build

do-install:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-install

.include "../../mk/bsd.pkg.mk"
