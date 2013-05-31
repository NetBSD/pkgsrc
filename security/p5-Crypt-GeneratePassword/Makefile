# $NetBSD: Makefile,v 1.8 2013/05/31 12:41:54 wiz Exp $
#

DISTNAME=		Crypt-GeneratePassword-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-GeneratePassword/
COMMENT=		Generate secure random pronounceable passwords

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GeneratePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
