# $NetBSD: Makefile,v 1.11 2004/12/20 11:31:05 grant Exp $
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

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
