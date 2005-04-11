# $NetBSD: Makefile,v 1.12 2005/04/11 21:45:33 tv Exp $
#

DISTNAME=	perldap-1.2.2
PKGNAME=	p5-LDAP-1.2.2
SVR4_PKGNAME=	p5lda
PKGREVISION=	1
CATEGORIES=	devel perl5 databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/perldap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Perl5 module to build LDAP clients with perl

WRKSRC=		${WRKDIR}/perldap
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mozilla/LDAP/API/.packlist

MAKE_ENV+=	LDAPSDKDIR=${BUILDLINK_PREFIX.ldapsdk}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

.include "../../devel/ldapsdk/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
