# $NetBSD: Makefile,v 1.7 2002/10/20 21:48:16 seb Exp $

DISTNAME=       ldapsdk_12311998
PKGNAME=        ldapsdk-12311998
CATEGORIES=	devel databases
MASTER_SITES=   ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

CONFLICTS+=	openldap*

USE_GMAKE=	yes
USE_PERL5=	build
USE_BUILDLINK2=	yes
WRKSRC=         ${WRKDIR}/mozilla

SCRIPTS_ENV+=	GMAKE=${GMAKE}
SCRIPTS_ENV+=	LN=${LN}

do-build:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-build

do-install:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/pre-install

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
