# $NetBSD: Makefile,v 1.9 2023/07/06 09:40:09 wiz Exp $

DISTNAME=	Test-CPAN-Meta-JSON-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BA/BARBIE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::CPAN::Meta::JSON
COMMENT=	Validate a META.json file within a CPAN distribution
LICENSE=	artistic-2.0

DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON

PERL5_PACKLIST=		auto/Test/CPAN/Meta/JSON/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
