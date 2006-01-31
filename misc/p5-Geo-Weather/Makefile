# $NetBSD: Makefile,v 1.1.1.1 2006/01/31 21:37:46 jschauma Exp $
#

DISTNAME=		Geo-Weather-1.41
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geo-Weather/
COMMENT=		Perl5 weather retrieval module

DEPENDS+=		p5-libwww>=5.803nb1:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Weather/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
