# $NetBSD: Makefile,v 1.16 2011/08/19 01:11:29 obache Exp $
#

DISTNAME=		Business-ISBN-Data-20081208
PKGNAME=		p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5bid
CATEGORIES=		misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN-Data/
COMMENT=		Data for the p5-Business-ISBN package

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Business/ISBN/Data/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
