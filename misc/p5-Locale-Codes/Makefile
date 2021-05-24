# $NetBSD: Makefile,v 1.55 2021/05/24 19:53:08 wiz Exp $

DISTNAME=	Locale-Codes-3.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
