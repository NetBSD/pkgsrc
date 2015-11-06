# $NetBSD: Makefile,v 1.18 2015/11/06 07:11:07 wen Exp $
#

DISTNAME=		Crypt-RandPasswd-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RandPasswd/
COMMENT=		Random password generator based on FIPS-181
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/RandPasswd/.packlist

# Sometimes results in an endless loop.
TEST_TARGET=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
