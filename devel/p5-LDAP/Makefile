# $NetBSD: Makefile,v 1.6 2002/10/20 23:35:10 seb Exp $
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

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mozilla/LDAP/API/.packlist

WRKSRC=		${WRKDIR}/perldap

MAKE_ENV+=	LDAPSDKDIR=${BUILDLINK_PREFIX.ldapsdk}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

.include "../../devel/ldapsdk/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
