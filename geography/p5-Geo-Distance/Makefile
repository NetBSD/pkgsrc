# $NetBSD: Makefile,v 1.23 2020/09/07 11:10:38 wiz Exp $

DISTNAME=	Geo-Distance-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	geography perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BLUEFEET/Geo-Distance-0.20
COMMENT=	Calculate Distances and Closest Locations
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/Geo/Distance/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=		--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
