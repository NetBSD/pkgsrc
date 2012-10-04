# $NetBSD: Makefile,v 1.10 2012/10/04 09:19:19 asau Exp $
#

DISTNAME=	Geo-Distance-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bluefeet/Geo-Distance-0.11/Distance.pm
COMMENT=	Calculate Distances and Closest Locations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Geo/Distance/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=	--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
