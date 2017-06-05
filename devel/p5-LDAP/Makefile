# $NetBSD: Makefile,v 1.32 2017/06/05 14:23:09 ryoon Exp $
#

DISTNAME=	perldap-1.4.1
# remove 'per' and 'ldap' part into uppercase (perldap -> LDAP)
PKGNAME=	p5-${DISTNAME:S/per//tu}
PKGREVISION=	4
CATEGORIES=	devel perl5 databases
MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=directory/perldap/ancient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/directory/perldap.html
COMMENT=	Perl5 module to build LDAP clients with perl
LICENSE=	mpl-1.0

PERL5_PACKLIST=	auto/Mozilla/LDAP/API/.packlist

MAKE_ENV+=	LDAPSDKDIR=${BUILDLINK_PREFIX.ldapsdk}
MAKE_ENV+=	LDAPSDKSSL="no"
MAKE_ENV+=	LDAPV3ON="yes"

.include "../../devel/ldapsdk/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
