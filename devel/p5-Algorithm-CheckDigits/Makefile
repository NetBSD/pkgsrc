# $NetBSD: Makefile,v 1.21 2021/02/11 00:34:50 wen Exp $

DISTNAME=	Algorithm-CheckDigits-v1.3.5
PKGNAME=	p5-${DISTNAME:S/-v/-/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-CheckDigits
COMMENT=	Perl extension to generate and test check digits
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Probe-Perl-[0-9]*:../../devel/p5-Probe-Perl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Algorithm/CheckDigits/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
