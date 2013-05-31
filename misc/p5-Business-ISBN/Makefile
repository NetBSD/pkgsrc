# $NetBSD: Makefile,v 1.27 2013/05/31 12:41:27 wiz Exp $
#

DISTNAME=		Business-ISBN-2.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5bui
CATEGORIES=		misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN/
COMMENT=		Perl5 module to work with International Standard Book Numbers (ISBNs)

DEPENDS+=		p5-Business-ISBN-Data>=20081020:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
