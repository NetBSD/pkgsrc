# $NetBSD: Makefile,v 1.24 2011/08/14 13:45:15 obache Exp $
#

DISTNAME=		Business-ISBN-2.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5bui
CATEGORIES=		misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN/
COMMENT=		Perl5 module to work with International Standard Book Numbers (ISBNs)

PKG_DESTDIR_SUPPORT=	user-destdir
DEPENDS+=		p5-Business-ISBN-Data>=20081020:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
