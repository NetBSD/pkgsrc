# $NetBSD: Makefile,v 1.13 2019/06/30 20:14:37 nia Exp $
#

DISTNAME=	Check-ISA-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MANWAR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Check-ISA
COMMENT=	DWIM, correct checking of an object's class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Check/ISA/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
