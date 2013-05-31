# $NetBSD: Makefile,v 1.14 2013/05/31 12:41:55 wiz Exp $
#

DISTNAME=		Crypt-RandPasswd-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RandPasswd/
COMMENT=		Random password generator based on FIPS-181

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/RandPasswd/.packlist

# Sometimes results in an endless loop.
TEST_TARGET=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
