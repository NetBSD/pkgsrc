# $NetBSD: Makefile,v 1.2 2009/03/08 22:03:50 seb Exp $
#

DISTNAME=	Net-LDAP-Server-Test-0.08_01
PKGNAME=	p5-Net-LDAP-Server-Test-0.80.100
CATEGORIES=	devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KARMAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-LDAP-Server-Test/
COMMENT=	Perl 5 module to test Net::LDAP code

DEPENDS+=	p5-Net-LDAP-Server-[0-9]*:../../net/p5-Net-LDAP-Server
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Net/LDAP/Server/Test/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
