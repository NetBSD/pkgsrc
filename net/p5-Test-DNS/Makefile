# $NetBSD: Makefile,v 1.16 2019/08/11 13:22:27 wiz Exp $
#

DISTNAME=	Test-DNS-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-DNS
COMMENT=	Perl 5 module to test DNS queries and zone configuration
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/DNS/.packlist

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Moose>=0.8:../../devel/p5-Moose
DEPENDS+=	p5-Net-DNS>=0:../../net/p5-Net-DNS
DEPENDS+=	p5-Set-Object>=0:../../devel/p5-Set-Object
DEPENDS+=	p5-Test-Deep>=0:../../devel/p5-Test-Deep

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
