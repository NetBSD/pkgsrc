# $NetBSD: Makefile,v 1.15 2006/02/05 23:08:49 joerg Exp $
#

DISTNAME=	perldap-1.2.2
PKGNAME=	p5-LDAP-1.2.2
SVR4_PKGNAME=	p5lda
PKGREVISION=	3
CATEGORIES=	devel perl5 databases
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/perldap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Perl5 module to build LDAP clients with perl

WRKSRC=		${WRKDIR}/perldap
PERL5_PACKLIST=	auto/Mozilla/LDAP/API/.packlist

MAKE_ENV+=	LDAPSDKDIR=${BUILDLINK_PREFIX.ldapsdk}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

.include "../../devel/ldapsdk/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
