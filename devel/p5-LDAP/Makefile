# $NetBSD: Makefile,v 1.21 2011/08/14 12:26:13 obache Exp $
#

DISTNAME=	perldap-1.2.2
PKGNAME=	p5-LDAP-1.2.2
PKGREVISION=	6
SVR4_PKGNAME=	p5lda
CATEGORIES=	devel perl5 databases
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=directory/perldap/ancient/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Perl5 module to build LDAP clients with perl

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/perldap
PERL5_PACKLIST=	auto/Mozilla/LDAP/API/.packlist

MAKE_ENV+=	LDAPSDKDIR=${BUILDLINK_PREFIX.ldapsdk}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

.include "../../devel/ldapsdk/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
