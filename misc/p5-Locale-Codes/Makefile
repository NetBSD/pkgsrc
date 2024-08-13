# $NetBSD: Makefile,v 1.59 2024/08/13 01:18:37 wen Exp $

DISTNAME=	Locale-Codes-3.79
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Locale-Codes
COMMENT=	Perl5 module for ISO 3166, 639, 4217 and 15924 codes
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Inter-[0-9]*:../../devel/p5-Test-Inter

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/Codes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
