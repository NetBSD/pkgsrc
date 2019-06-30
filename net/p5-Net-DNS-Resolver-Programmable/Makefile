# $NetBSD: Makefile,v 1.14 2019/06/30 20:16:27 nia Exp $

DISTNAME=	Net-DNS-Resolver-Programmable-0.009
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	aniou@smutek.pl
HOMEPAGE=	https://metacpan.org/release/Net-DNS-Resolver-Programmable
COMMENT=	Net::DNS::Resolver descendant class for offline emulation of DNS
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Net/DNS/Resolver/Programmable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
