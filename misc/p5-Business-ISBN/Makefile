# $NetBSD: Makefile,v 1.17 2007/06/10 09:36:31 obache Exp $
#

DISTNAME=		Business-ISBN-1.84
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bui
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN/
COMMENT=		Perl5 module to work with International Standard Book Numbers (ISBNs)

DEPENDS+=		p5-Business-ISBN-Data>=1.09:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
