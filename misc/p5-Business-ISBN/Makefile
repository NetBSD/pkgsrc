# $NetBSD: Makefile,v 1.7 2003/07/17 21:49:38 grant Exp $
#

DISTNAME=		Business-ISBN-1.60
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bui
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-ISBN/ISBN.html
COMMENT=		perl5 module to work with International Standard Book Numbers (ISBNs)

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
