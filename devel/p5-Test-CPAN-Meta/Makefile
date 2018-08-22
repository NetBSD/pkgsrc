# $NetBSD: Makefile,v 1.4 2018/08/22 09:44:44 wiz Exp $

DISTNAME=	Test-CPAN-Meta-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/B/BA/BARBIE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/B/BA/BARBIE/
COMMENT=	Validate your CPAN META.yml files
LICENSE=	artistic-2.0

PERL5_PACKLIST=	auto/Test/CPAN/Meta/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
