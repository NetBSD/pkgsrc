# $NetBSD: Makefile,v 1.1.1.1 1999/05/18 21:22:26 hwr Exp $

DISTNAME=       ldapsdk_12311998
PKGNAME=        ldapsdk-12311998
CATEGORIES=	devel databases
MASTER_SITES=   ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/directory/

BUILD_DEPENDS+=		gmake-3.77:../../devel/

CONFLICTS+=	openldap*

WRKSRC=         ${WRKDIR}/mozilla

#
# empty target. scripts/pre-build does the actual work
do-build:

#
# empty target. scripts/pre-install does the actual work
do-install:

.include "../../mk/bsd.pkg.mk"
