# $NetBSD: Makefile,v 1.5 2019/07/01 21:35:43 nia Exp $

DISTNAME=	Test-CPAN-Meta-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
