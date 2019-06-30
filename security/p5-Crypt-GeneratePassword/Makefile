# $NetBSD: Makefile,v 1.16 2019/06/30 20:16:38 nia Exp $
#

DISTNAME=		Crypt-GeneratePassword-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-GeneratePassword
COMMENT=		Generate secure random pronounceable passwords
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GeneratePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
