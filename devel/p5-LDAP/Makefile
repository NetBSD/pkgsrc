# $NetBSD: Makefile,v 1.1.1.1 1999/05/24 08:32:35 hwr Exp $
#

DISTNAME=	perldap-1.2.2
PKGNAME=	p5-LDAP-1.2.2
CATEGORIES=	devel perl databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/perldap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbd.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html

DEPENDS+=	ldapsdk-12311998:../../devel/ldapsdk

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/perldap

do-configure:
	@cd ${WRKSRC}; ${SETENV} LDAPSDKDIR=${LOCALBASE} LDAPSDKSSL="no" LDAPV3ON=yes ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
