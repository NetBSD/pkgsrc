# $NetBSD: Makefile,v 1.49 2012/12/06 13:09:04 wen Exp $

DISTNAME=		Net-DNS-0.69
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ndn
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}		\
			http://www.net-dns.org/download/

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.net-dns.org/
COMMENT=		Perl5 module for DNS resolution
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=		{p5-Test-Simple>=0.44,perl{,-thread}>=5.8.0}:../../devel/p5-Test-Simple
DEPENDS+=		p5-Digest-HMAC>=1.0:../../security/p5-Digest-HMAC
DEPENDS+=		p5-Digest-MD5>=2.12:../../security/p5-Digest-MD5
DEPENDS+=		p5-MIME-Base64>=2.11:../../converters/p5-MIME-Base64
DEPENDS+=		p5-Net-IP>=1.20:../../net/p5-Net-IP

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-Net-DNS
PKG_SUPPORTED_OPTIONS=	inet6 online-tests
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=		p5-IO-Socket-INET6>=2.01:../../net/p5-IO-Socket-INET6
DEPENDS+=		p5-Socket6-[0-9]*:../../net/p5-Socket6
MAKE_PARAMS+=		--IPv6-tests
.else
MAKE_PARAMS+=		--no-IPv6-tests
.endif

.if !empty(PKG_OPTIONS:Monline-tests)
MAKE_PARAMS+=		--online-tests
.else
MAKE_PARAMS+=		--no-online-tests
.endif

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/Net/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
