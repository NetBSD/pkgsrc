# $NetBSD: Makefile,v 1.5 2002/10/07 22:34:24 seb Exp $
#

DISTNAME=		Business-ISBN-1.60
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bui
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-ISBN/ISBN.html
COMMENT=		perl5 module to work with International Standard Book Numbers (ISBNs)

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/ISBN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
