# $NetBSD: Makefile,v 1.12 2008/11/11 09:11:05 rhaen Exp $
#

DISTNAME=		Business-ISBN-Data-20081020
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=	p5bid
CATEGORIES=		misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=		Data for the p5-Business-ISBN package

PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=		p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Business/ISBN/Data/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
