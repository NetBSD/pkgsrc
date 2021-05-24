# $NetBSD: Makefile,v 1.23 2021/05/24 19:51:45 wiz Exp $

DISTNAME=		Test-LongString-0.17
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-LongString
COMMENT=		Perl5 module to test strings for equality
LICENSE=		${PERL5_LICENSE}

PERL5_REQD+=		5.10.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/LongString/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
