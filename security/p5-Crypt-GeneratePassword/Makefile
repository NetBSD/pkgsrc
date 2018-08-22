# $NetBSD: Makefile,v 1.15 2018/08/22 09:46:22 wiz Exp $
#

DISTNAME=		Crypt-GeneratePassword-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-GeneratePassword/
COMMENT=		Generate secure random pronounceable passwords
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GeneratePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
