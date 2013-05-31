# $NetBSD: Makefile,v 1.8 2013/05/31 12:40:43 wiz Exp $
#

DISTNAME=		ShipIt-0.55
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BR/BRADFITZ/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/ShipIt/
COMMENT=		Perl software release tool
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/ShipIt/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
