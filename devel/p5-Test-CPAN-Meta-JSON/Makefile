# $NetBSD: Makefile,v 1.2 2019/11/03 10:16:04 rillig Exp $

DISTNAME=	Test-CPAN-Meta-JSON-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/B/BA/BARBIE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/B/BA/BARBIE/
COMMENT=	Validate a META.json file within a CPAN distribution
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Test/CPAN/Meta/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
