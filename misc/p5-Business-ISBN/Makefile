# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:28 veego Exp $
#

DISTNAME=		Business-ISBN-1.60
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bui
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
