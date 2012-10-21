# $NetBSD: Makefile,v 1.19 2012/10/21 22:10:44 wiz Exp $
#

DISTNAME=	Business-ISBN-Data-20120719.001
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5bid
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=	Data for the p5-Business-ISBN package

PERL5_PACKLIST=	auto/Business/ISBN/Data/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
