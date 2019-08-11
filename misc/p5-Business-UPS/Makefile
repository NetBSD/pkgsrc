# $NetBSD: Makefile,v 1.27 2019/08/11 13:21:57 wiz Exp $
#

DISTNAME=		Business-UPS-2.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Business-UPS/README.html
COMMENT=		Perl5 module to handle UPS rate calculation and package tracking

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

PERL5_PACKLIST=		auto/Business/UPS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
