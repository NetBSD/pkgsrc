# $NetBSD: Makefile,v 1.26 2013/08/15 09:06:18 wen Exp $
#

DISTNAME=		Crypt-Blowfish-2.14
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cbl
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-Blowfish/
COMMENT=		Perl5 Blowfish implementation
# LICENSE=		unclear

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# recommended for tests
BUILD_DEPENDS+=		p5-Crypt-CBC>=1.25:../../security/p5-Crypt-CBC

CRYPTO=			YES
USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/Blowfish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
