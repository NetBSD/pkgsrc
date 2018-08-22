# $NetBSD: Makefile,v 1.12 2018/08/22 09:44:27 wiz Exp $
#

DISTNAME=		Ouch-0.0500
PKGNAME=        	p5-${DISTNAME}
PKGREVISION=        	1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RI/RIZEN/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Ouch/
COMMENT=		Exceptions that don't hurt
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test-Trap-[0-9]*:../../devel/p5-Test-Trap

PERL5_PACKLIST=		auto/Ouch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
