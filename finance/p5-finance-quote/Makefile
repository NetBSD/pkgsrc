# $NetBSD: Makefile,v 1.1.1.1 2001/10/30 13:23:03 damon Exp $

DISTNAME=	Finance-Quote-1.06
PKGNAME=	p5-finance-quote-1.06
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Finance/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://finance-quote.sourceforge.net/
COMMENT=	perl module to get stock quotes from Yahoo

DEPENDS+=	p5-HTML-TableExtract-1.*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Finance/Quote/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
