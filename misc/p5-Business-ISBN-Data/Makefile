# $NetBSD: Makefile,v 1.18 2012/10/08 09:57:32 asau Exp $
#

DISTNAME=		Business-ISBN-Data-20081208
PKGNAME=		p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5bid
CATEGORIES=		misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=		Data for the p5-Business-ISBN package

PERL5_PACKLIST=		auto/Business/ISBN/Data/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
