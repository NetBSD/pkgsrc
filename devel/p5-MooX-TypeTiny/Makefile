# $NetBSD: Makefile,v 1.4 2020/09/07 09:35:21 wiz Exp $

DISTNAME=	MooX-TypeTiny-0.002003
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/H/HA/HAARG/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/H/HA/HAARG/
COMMENT=	Optimized type checks for Moo + Type::Tiny
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/MooX/TypeTiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
