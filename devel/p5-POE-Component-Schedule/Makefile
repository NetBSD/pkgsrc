# $NetBSD: Makefile,v 1.13 2019/06/30 20:15:30 nia Exp $

DISTNAME=	POE-Component-Schedule-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POE-Component-Schedule
COMMENT=	Schedule POE events using DateTime::Set iterators
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-POE>=1.287:../../devel/p5-POE
DEPENDS+=	p5-DateTime>=0.48:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Set>=0.25:../../time/p5-DateTime-Set
DEPENDS+=	p5-DateTime-TimeZone>=1.13:../../time/p5-DateTime-TimeZone

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/POE/Component/Schedule/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
