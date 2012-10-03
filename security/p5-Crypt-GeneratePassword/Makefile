# $NetBSD: Makefile,v 1.6 2012/10/03 21:57:28 wiz Exp $
#

DISTNAME=		Crypt-GeneratePassword-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-GeneratePassword/
COMMENT=		Generate secure random pronounceable passwords

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/GeneratePassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
