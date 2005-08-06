# $NetBSD: Makefile,v 1.11 2005/08/06 06:19:19 jlam Exp $

DISTNAME=	Finance-Quote-1.08
PKGNAME=	p5-finance-quote-1.08
PKGREVISION=	3
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Finance/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://finance-quote.sourceforge.net/
COMMENT=	Perl module to get stock quotes from Yahoo

DEPENDS+=	p5-HTML-TableExtract-1.*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

PERL5_PACKLIST=		auto/Finance/Quote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
