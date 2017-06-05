# $NetBSD: Makefile,v 1.11 2017/06/05 14:24:19 ryoon Exp $
#

DISTNAME=	Net-DNS-Resolver-Programmable-v0.003
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	7
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	aniou@smutek.pl
HOMEPAGE=	http://search.cpan.org/dist/Net-DNS-Resolver-Programmable/
COMMENT=	Net::DNS::Resolver descendant class for offline emulation of DNS
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.10.0,p5-version-[0-9]*}:../../devel/p5-version
DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

USE_LANGUAGES=	# empty

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/DNS/Resolver/Programmable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
