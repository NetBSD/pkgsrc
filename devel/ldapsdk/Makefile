# $NetBSD: Makefile,v 1.3 2000/01/11 21:01:05 hubertf Exp $

DISTNAME=       ldapsdk_12311998
PKGNAME=        ldapsdk-12311998
CATEGORIES=	devel databases
MASTER_SITES=   ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/directory/

CONFLICTS+=	openldap*

USE_GMAKE=	yes
USE_PERL5=	yes
WRKSRC=         ${WRKDIR}/mozilla

#
# empty target. scripts/pre-build does the actual work
do-build:

#
# empty target. scripts/pre-install does the actual work
do-install:

.include "../../mk/bsd.pkg.mk"
