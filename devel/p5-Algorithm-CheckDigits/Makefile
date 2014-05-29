# $NetBSD: Makefile,v 1.10 2014/05/29 23:35:38 wiz Exp $

DISTNAME=	Algorithm-CheckDigits-v1.3.0
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Algorithm-CheckDigits/
COMMENT=	Perl extension to generate and test check digits
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Probe-Perl-[0-9]*:../../devel/p5-Probe-Perl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Algorithm/CheckDigits/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
