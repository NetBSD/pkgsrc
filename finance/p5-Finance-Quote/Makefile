# $NetBSD: Makefile,v 1.29 2017/06/05 14:23:58 ryoon Exp $

DISTNAME=	Finance-Quote-1.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Finance/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://finance-quote.sourceforge.net/
COMMENT=	Perl module to get stock quotes from Yahoo
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-HTML-TableExtract>=1.0:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

REPLACE_PERL=	lib/Finance/Quote.pm
REPLACE_PERL+=	lib/Finance/Quote/*.pm
REPLACE_PERL+=	lib/Finance/Quote/Yahoo/*.pm

CONFLICTS=	p5-finance-quote-[0-9]*

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Finance/Quote/.packlist

# for patchd file
pre-configure:
	${RM} -f ${WRKSRC}/lib/Finance/Quote/VWD.pm.orig

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
