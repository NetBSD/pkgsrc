# $NetBSD: Makefile,v 1.7 2020/08/31 18:08:58 wiz Exp $

DISTNAME=	Test-CPAN-Meta-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/B/BA/BARBIE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/B/BA/BARBIE/
COMMENT=	Validate your CPAN META.yml files
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Test/CPAN/Meta/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
