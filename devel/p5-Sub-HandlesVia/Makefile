# $NetBSD: Makefile,v 1.9 2022/06/28 11:33:15 wiz Exp $

DISTNAME=	Sub-HandlesVia-0.016
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Sub::HandlesVia
COMMENT=	Alternative handles_via implementation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Method-Modifiers-[0-9]*:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny
DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny
DEPENDS+=	p5-Role-Tiny-[0-9]*:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
TEST_DEPENDS+=	p5-MooX-TypeTiny-[0-9]*:../../devel/p5-MooX-TypeTiny
TEST_DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
TEST_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/Sub/HandlesVia/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
