# $NetBSD: Makefile,v 1.20 2023/07/06 09:40:59 wiz Exp $
#

DISTNAME=	Locale-US-3.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Locale-US
COMMENT=	Perl 5 module to maps US two-letter codes to states and vice versa
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Section-Simple-[0-9]*:../../devel/p5-Data-Section-Simple

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Locale/US/.packlist
REPLACE_PERL=	kruft2codes.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
