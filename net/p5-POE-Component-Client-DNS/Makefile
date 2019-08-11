# $NetBSD: Makefile,v 1.22 2019/08/11 13:22:25 wiz Exp $
#

DISTNAME=	POE-Component-Client-DNS-1.054
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POE-Component-Client-DNS
COMMENT=	Non-blocking, concurrent DNS requests
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.294:../../devel/p5-POE
DEPENDS+=	p5-Net-DNS>=0.65:../../net/p5-Net-DNS
DEPENDS+=	p5-Test-NoWarnings>=1.02:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=		auto/POE/Component/Client/DNS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
