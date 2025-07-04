# $NetBSD: Makefile,v 1.14 2025/07/04 08:46:44 wiz Exp $

DISTNAME=	Test-CPAN-Meta-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BA/BARBIE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::CPAN::Meta
COMMENT=	Validate your CPAN META.yml files
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Test/CPAN/Meta/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
