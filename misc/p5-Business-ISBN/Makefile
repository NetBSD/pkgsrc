# $NetBSD: Makefile,v 1.1.1.1 2001/02/19 15:50:14 wiz Exp $
#

DISTNAME=		Business-ISBN-20001010
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Business/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/Business-ISBN/ISBN.html
COMMENT=		perl5 module to work with International Standard Book Numbers (ISBNs)

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Business/ISBN/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
