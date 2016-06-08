# $NetBSD: Makefile,v 1.8 2016/06/08 19:22:38 wiz Exp $
#

DISTNAME=	Check-ISA-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NU/NUFFIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Check-ISA/
COMMENT=	DWIM, correct checking of an object's class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Check/ISA/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
