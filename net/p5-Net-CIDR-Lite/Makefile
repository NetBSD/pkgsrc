# $NetBSD: Makefile,v 1.24 2018/08/22 09:45:58 wiz Exp $
#

DISTNAME=		Net-CIDR-Lite-0.21
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-CIDR-Lite/
COMMENT=		Perl extension for merging IPv4/v6 CIDR addresses
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Net/CIDR/Lite/.packlist
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
