# $NetBSD: Makefile,v 1.5 2019/08/11 13:22:17 wiz Exp $

DISTNAME=	Net-DNS-Resolver-Mock-1.20171219
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::DNS::Resolver::Mock
COMMENT=	Mock a DNS Resolver object for testing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

#USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Net/DNS/Resolver/Mock/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
