# $NetBSD: Makefile,v 1.20 2022/06/28 11:34:04 wiz Exp $
#

DISTNAME=	GD-SVG-0.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GD-SVG
COMMENT=	Enables SVG output from scripts written using GD
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=		p5-SVG-[0-9]*:../../graphics/p5-SVG

PERL5_PACKLIST=		auto/GD/SVG/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
