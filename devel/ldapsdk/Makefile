# $NetBSD: Makefile,v 1.4 2001/02/16 14:38:33 wiz Exp $

DISTNAME=       ldapsdk_12311998
PKGNAME=        ldapsdk-12311998
CATEGORIES=	devel databases
MASTER_SITES=   ftp://ftp.mozilla.org/pub/directory/c-sdk/ldap/

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.mozilla.org/directory/
COMMENT=	The LDAP C-SDK from the Mozilla projekt

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
