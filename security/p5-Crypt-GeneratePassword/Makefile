# $NetBSD: Makefile,v 1.18 2020/08/31 18:11:12 wiz Exp $
#

DISTNAME=		Crypt-GeneratePassword-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
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
