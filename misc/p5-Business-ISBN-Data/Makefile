# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:38 tv Exp $
#

DISTNAME=		Business-ISBN-Data-1.08
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bid
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=		Data for the p5-Business-ISBN package

DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/ISBN/Data/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
