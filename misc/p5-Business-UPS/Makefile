# $NetBSD: Makefile,v 1.4 2002/10/27 20:48:59 seb Exp $
#

DISTNAME=		Business-UPS-1.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5buu
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Business-UPS/README.html
COMMENT=		Perl5 module to handle UPS rate calculation and package tracking

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/UPS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
