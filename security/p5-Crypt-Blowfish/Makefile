# $NetBSD: Makefile,v 1.41 2023/07/06 09:41:20 wiz Exp $
#

DISTNAME=		Crypt-Blowfish-2.14
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-Blowfish
COMMENT=		Perl5 Blowfish implementation
# LICENSE=		unclear

# recommended for tests
TOOL_DEPENDS+=		p5-Crypt-CBC>=1.25:../../security/p5-Crypt-CBC

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/Blowfish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
