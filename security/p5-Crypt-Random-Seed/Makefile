# $NetBSD: Makefile,v 1.1 2013/07/14 04:41:51 wen Exp $

DISTNAME=		Crypt-Random-Seed-0.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Random-Seed/
COMMENT=		Simple method to get strong randomness
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Crypt-Random-TESHA2>=0:../../security/p5-Crypt-Random-TESHA2

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/Random/Seed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
