# $NetBSD: Makefile,v 1.3 2002/10/27 20:48:59 seb Exp $

DISTNAME=	Finance-Quote-1.06
PKGNAME=	p5-finance-quote-1.06
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Finance/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://finance-quote.sourceforge.net/
COMMENT=	perl module to get stock quotes from Yahoo

DEPENDS+=	p5-HTML-TableExtract-1.*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Finance/Quote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
