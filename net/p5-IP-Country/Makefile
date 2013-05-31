# $NetBSD: Makefile,v 1.13 2013/05/31 12:41:36 wiz Exp $
#

DISTNAME=		IP-Country-2.27
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
SVR4_PKGNAME=		p5icy
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IP/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IP-Country/
COMMENT=		Fast lookup of country codes from IP addresses
#LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Geography-Countries-[0-9]*:../../geography/p5-Geography-Countries

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IP/Country/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
