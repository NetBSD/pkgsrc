# $NetBSD: Makefile,v 1.16 2004/04/27 04:59:42 snj Exp $

DISTNAME=	ldapsdk_12311998
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

CONFLICTS+=	openldap-[0-9]*

WRKSRC=		${WRKDIR}/mozilla
USE_GNU_TOOLS+=	make
USE_PERL5=	build
USE_BUILDLINK3=	yes

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

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
