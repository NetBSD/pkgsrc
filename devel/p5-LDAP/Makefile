# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:17 veego Exp $
#

DISTNAME=	perldap-1.2.2
PKGNAME=	p5-LDAP-1.2.2
SVR4_PKGNAME=	p5lda
CATEGORIES=	devel perl5 databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/perldap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbd.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Perl5 module to build LDAP clients with perl

DEPENDS+=	ldapsdk-12311998:../../devel/ldapsdk

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mozilla/LDAP/API/.packlist

WRKSRC=		${WRKDIR}/perldap

MAKE_ENV+=	LDAPSDKDIR=${LOCALBASE}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
