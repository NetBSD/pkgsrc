# $NetBSD: Makefile,v 1.14 2022/06/28 11:32:50 wiz Exp $

DISTNAME=	MooX-late-0.100
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooX-late
COMMENT=	Easily translate Moose code to Moo
LICENSE=	gnu-gpl-v1 OR artistic

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Sub-HandlesVia-[0-9]*:../../devel/p5-Sub-HandlesVia
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=	auto/MooX/late/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
