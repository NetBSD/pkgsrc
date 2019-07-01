# $NetBSD: Makefile,v 1.19 2019/07/01 21:35:46 nia Exp $

DISTNAME=	Geo-Distance-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BLUEFEET/Geo-Distance-0.20
COMMENT=	Calculate Distances and Closest Locations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/Distance/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=	--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
