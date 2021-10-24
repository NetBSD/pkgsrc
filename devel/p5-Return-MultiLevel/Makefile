# $NetBSD: Makefile,v 1.14 2021/10/24 08:24:55 wen Exp $

DISTNAME=		Return-MultiLevel-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PL/PLICEASE/}

MAINTAINER=		wen@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Return-MulitiLevel
COMMENT=		Perl module to enable returning from a nested call stack
LICENSE=		${PERL5_LICENSE}

DEPENDS=		p5-Data-Munge>=0.07:../../devel/p5-Data-Munge
BUILD_DEPENDS+=		p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Return/MultiLevel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
