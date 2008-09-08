# $NetBSD: Makefile,v 1.1.1.1 2008/09/08 08:41:21 he Exp $
#

DISTNAME=		Geo-Mercator-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5gme
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geo-Mercator/
COMMENT=		Perl5 module computing Mercator Projection into meters

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Mercator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
