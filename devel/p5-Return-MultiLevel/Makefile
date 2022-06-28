# $NetBSD: Makefile,v 1.16 2022/06/28 11:33:10 wiz Exp $

DISTNAME=		Return-MultiLevel-0.08
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PL/PLICEASE/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Return-MulitiLevel
COMMENT=		Perl module to enable returning from a nested call stack
LICENSE=		${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Return/MultiLevel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
