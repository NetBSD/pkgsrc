# $NetBSD: Makefile,v 1.5 2010/08/21 16:35:21 seb Exp $
#

DISTNAME=	Geo-IPfree-0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~gmpassos/Geo-IPfree-0.2/
COMMENT=	Gets country name by IP or hostname

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Geo/IPfree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
