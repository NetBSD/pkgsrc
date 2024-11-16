# $NetBSD: Makefile,v 1.10 2024/11/16 12:05:14 wiz Exp $

DISTNAME=	Test-CPAN-Meta-JSON-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
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
