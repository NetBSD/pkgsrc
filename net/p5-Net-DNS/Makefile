# $NetBSD: Makefile,v 1.8 2003/02/17 15:28:02 dillo Exp $
#

DISTNAME=		Net-DNS-0.29
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ndn
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}		\
			http://www.net-dns.org/download/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.net-dns.org/
COMMENT=		Net::DNS - Perl DNS Resolver Module

BUILD_DEPENDS+=		p5-Test-Simple>=0.44:../../devel/p5-Test-Simple
DEPENDS+=		p5-Digest-HMAC>=1.0:../../security/p5-Digest-HMAC
DEPENDS+=		p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64

BUILDLINK_DEPENDS.perl=	perl>=5.6.0
USE_BUILDLINK2=		YES
TEST_TARGET=		test

PERL5_CONFIGURE=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
