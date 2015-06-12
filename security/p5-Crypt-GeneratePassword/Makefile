# $NetBSD: Makefile,v 1.10 2015/06/12 10:51:05 wiz Exp $
#

DISTNAME=		Crypt-GeneratePassword-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-GeneratePassword/
COMMENT=		Generate secure random pronounceable passwords

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GeneratePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
