# $NetBSD: Makefile,v 1.16 2004/01/05 22:16:25 jlam Exp $
#

DISTNAME=		Net-DNS-0.42
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ndn
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}		\
			http://www.net-dns.org/download/

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.net-dns.org/
COMMENT=		Perl5 module for DNS resolution

BUILD_DEPENDS+=		p5-Test-Simple>=0.44:../../devel/p5-Test-Simple
DEPENDS+=		p5-Digest-HMAC>=1.0:../../security/p5-Digest-HMAC
DEPENDS+=		p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Digest-MD5>=2.12:../../security/p5-Digest-MD5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_DEPENDS.perl=	perl>=5.6.0
USE_BUILDLINK3=		YES

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
