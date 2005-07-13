# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:33 jlam Exp $
#

DISTNAME=		Business-ISBN-1.78
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bui
PKGREVISION=		1
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Business-ISBN/
COMMENT=		Perl5 module to work with International Standard Book Numbers (ISBNs)

DEPENDS+=		p5-Business-ISBN-Data-[0-9]*:../../misc/p5-Business-ISBN-Data

PERL5_PACKLIST=		auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
