# $NetBSD: Makefile,v 1.4 2022/06/28 11:32:03 wiz Exp $

DISTNAME=	Class-Refresh-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Class::Refresh
COMMENT=	Perl5 module for refreshing classes during runtime
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Load-[0-9]*:../../devel/p5-Class-Load
DEPENDS+=	p5-Class-Unload-[0-9]*:../../devel/p5-Class-Unload
DEPENDS+=	p5-Devel-OverrideGlobalRequire-[0-9]*:../../devel/p5-Devel-OverrideGlobalRequire
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose

PERL5_PACKLIST=		auto/Class/Refresh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
