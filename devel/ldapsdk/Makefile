# $NetBSD: Makefile,v 1.5 2001/05/17 08:38:43 abs Exp $

DISTNAME=       ldapsdk_12311998
PKGNAME=        ldapsdk-12311998
CATEGORIES=	devel databases
MASTER_SITES=   ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	LDAP C-SDK from the Mozilla project

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
