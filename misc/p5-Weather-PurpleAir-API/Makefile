# $NetBSD: Makefile,v 1.5 2022/07/18 20:45:04 mrg Exp $

DISTNAME=	Weather-PurpleAir-API-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	misc devel perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Weather/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TT/TTKCIAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Weather-PurpleAir-API
COMMENT=	Perl5 library for PurpleAir API
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Weather/PurpleAir/API/.packlist

DEPENDS+=       p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=       p5-File-Valet>=1.07:../../devel/p5-File-Valet
DEPENDS+=       p5-String-Similarity>=1.04:../../textproc/p5-String-Similarity

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
