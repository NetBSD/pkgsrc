# $NetBSD: Makefile,v 1.3 2008/10/19 19:18:10 he Exp $
#

DISTNAME=	Geo-Distance-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~bluefeet/Geo-Distance-0.11/Distance.pm
COMMENT=	Calculate Distances and Closest Locations

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Geo/Distance/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
