# $NetBSD: Makefile,v 1.25 2023/07/06 09:40:17 wiz Exp $
#

DISTNAME=		Test-POE-Server-TCP-1.20
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-POE-Server-TCP
COMMENT=		POE Component providing TCP server services for tests
LICENSE=		artistic-2.0

DEPENDS+=		p5-POE>=1.004:../../devel/p5-POE

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/POE/Server/TCP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
