# $NetBSD: Makefile,v 1.1.1.1 2009/03/12 04:40:57 seb Exp $
#

DISTNAME=	Net-LDAP-Class-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-LDAP-Class/
COMMENT=	Perl 5 module providing an object-relational mapper for Net::LDAP

DEPENDS+=	p5-Rose-Object-[0-9]*:../../devel/p5-Rose-Object
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-LDAP
DEPENDS+=	p5-Net-LDAP-Batch-[0-9]*:../../devel/p5-Net-LDAP-Batch
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
BUILD_DEPENDS+=	p5-Net-LDAP-Server-Test>=0.8.0.01:../../devel/p5-Net-LDAP-Server-Test

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/LDAP/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
