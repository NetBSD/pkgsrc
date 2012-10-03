# $NetBSD: Makefile,v 1.17 2012/10/03 16:10:13 asau Exp $

DISTNAME=	Finance-Quote-1.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Finance/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://finance-quote.sourceforge.net/
COMMENT=	Perl module to get stock quotes from Yahoo
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-HTML-TableExtract>=1.0:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-libwww>=5.48:../../www/p5-libwww

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
