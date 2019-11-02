# $NetBSD: Makefile,v 1.1 2019/11/02 13:20:16 mef Exp $

DISTNAME=	Test-CPAN-Meta-JSON-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/B/BA/BARBIE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/B/BA/BARBIE/
COMMENT=	Validate a META.json file within a CPAN distribution
LICENSE=	artistic-2.0

PERL5_PACKLIST=         auto/Test/CPAN/Meta/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
