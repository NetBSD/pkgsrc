# $NetBSD: Makefile,v 1.1.1.1 2008/10/25 20:22:07 abs Exp $

DISTNAME=	Algorithm-LUHN-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TA/TAYERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Algorithm::LUHN
COMMENT=	Calculate the Modulus 10 Double Add Double checksum

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Algorithm/LUHN/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
