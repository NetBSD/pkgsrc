# $NetBSD: Makefile,v 1.2 2019/08/11 13:22:24 wiz Exp $

DISTNAME=	Net-Works-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Net::Works
COMMENT=	Sane APIs for IP addresses and networks
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-AllUtils-[0-9]*:../../devel/p5-List-AllUtils
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Sub-Quote-[0-9]*:../../devel/p5-Sub-Quote
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-Math-Int128-[0-9]*:../../math/p5-Math-Int128
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/Net/Works/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
