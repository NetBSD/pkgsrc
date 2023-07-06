# $NetBSD: Makefile,v 1.12 2023/07/06 09:40:15 wiz Exp $

DISTNAME=	Test-Modern-0.013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Modern
COMMENT=		Precision testing for modern perl
LICENSE=		${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-API>=0.004:../../devel/p5-Test-API
TOOL_DEPENDS+=	p5-Test-Deep>=0.111:../../devel/p5-Test-Deep
TOOL_DEPENDS+=	p5-Test-Fatal>0.007:../../devel/p5-Test-Fatal
TOOL_DEPENDS+=	p5-Test-Warnings>0.009:../../devel/p5-Test-Warnings

DEPENDS+=		p5-Module-Runtime>=0.012:../../devel/p5-Module-Runtime
DEPENDS+=		p5-Exporter-Tiny>=0.030:../../devel/p5-Exporter-Tiny
DEPENDS+=		p5-Import-Into>=1.002000:../../devel/p5-Import-Into

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Modern/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
