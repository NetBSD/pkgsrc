# $NetBSD: Makefile,v 1.10 2019/06/30 20:15:40 nia Exp $

DISTNAME=		Return-MultiLevel-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MA/MAUKE/}

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
