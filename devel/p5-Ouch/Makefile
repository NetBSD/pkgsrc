# $NetBSD: Makefile,v 1.19 2022/06/28 11:32:59 wiz Exp $
#

DISTNAME=		Ouch-0.0501
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RI/RIZEN/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Ouch
COMMENT=		Exceptions that don't hurt
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap

PERL5_PACKLIST=		auto/Ouch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
